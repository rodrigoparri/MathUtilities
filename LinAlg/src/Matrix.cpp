#include "Matrix.h"
//#include "LinearAlg.cuh"
#include <iostream>

Matrix::Matrix() : m_rows(0), m_columns(0), m_buffer(nullptr), m_length(m_rows* m_columns) {}

Matrix::Matrix(int rows, int columns) : m_rows(rows), m_columns(columns), m_length(m_rows* m_columns) {
	m_buffer = new double[m_length];
	for (int i = 0; i < m_length; i++) {
		m_buffer[i] = 0.0;
	}
}

Matrix::Matrix(const Matrix& old) : m_rows(old.m_rows), m_columns(old.m_columns), m_length(m_length) {
	m_buffer = new double[m_length];
	for (int i = 0; i < m_length; i++) {
		m_buffer[i] = old.m_buffer[i];
	}
}

Matrix::~Matrix() {
	delete[] m_buffer;
}

bool Matrix::isSquare() {
	return (m_rows = m_columns);
}

bool Matrix::canAdd(const Matrix& right, const Matrix& left) {
	return (right.m_rows == left.m_rows && left.m_columns == right.m_columns);
}

bool Matrix::canMultiply(const Matrix& right, const Matrix& left) {
	return (right.m_rows == left.m_columns);
}

bool Matrix::indexOutRange(int row, int column) const {
	return row > m_rows || row < 0 || column > m_columns || column < 0;
}

void Matrix::identity() {
	if (isSquare()) {
		double flag;
		for (int i = 0; i < m_length; i++) {
			flag = (i % (m_columns + 1)) == 0;
			m_buffer[i] = flag;
		}
	}
}

void Matrix::set(const int row, const int column, const double data) {
	if (!indexOutRange(row, column)) {
		m_buffer[row * m_columns + column] = data;
	}
}

const double Matrix::get(int row, int column) const {
	if (!indexOutRange(row, column)) {
		return	m_buffer[row * m_columns + column];
	}
	else {
		std::cout << "Unable to get value.Index out or range. Returned 0.0";
		return 0.0;
	}
}

//	OPERATOR OVERLOADING
std::ostream& operator<<(std::ostream& left, const Matrix& right) {
	for (int i = 0; i < right.m_rows; i++) {
		for (int j = 0; j < right.m_columns; j++) {
			left << right.m_buffer[i * right.m_columns + j] << " ";
		}
		left << std::endl;
	}
	return left;
}

const Matrix operator+(const Matrix& right, const Matrix& left) {
	if (Matrix::canAdd(right, left)) {
		Matrix result(right.m_rows, right.m_columns);
		for (int i = 0; i < right.m_length; i++) {
			result.m_buffer[i] = right.m_buffer[i] + left.m_buffer[i];
		}
		return result;
	}
	else {
		std::cout << "Unable to add matrices" << std::endl;
		return right;
	}
}

const Matrix operator-(const Matrix& right, const Matrix& left) {
	if (Matrix::canAdd(right, left)) {
		Matrix result = Matrix();
		//cudaMatrixAdd(right.m_buffer, left.m_buffer, right.m_length);
		return result;
	}
	else {
		std::cout << "Unable to substract matrices" << std::endl;
		return right;
	}
}

const Matrix operator*(double scalar, const Matrix& matrix) {
	Matrix result(matrix.m_rows, matrix.m_columns);
	return result;
}

const Matrix operator*(const Matrix& right, const Matrix& left) {
	//cudaMatrixProduct
	Matrix result(right.m_rows, right.m_columns);
	return result;


}

