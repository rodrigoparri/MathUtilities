#pragma once
#include <iostream>
class Matrix
{
	// PRIVATE VARIABLES
private:
	double* m_buffer = nullptr;
	//PUBLIC VARIABLES
public:
	int m_rows;
	int m_columns;
	int m_length;

	//PUBLIC METHODS
public:
	Matrix();
	Matrix(int rows, int columns);
	Matrix(const Matrix& old);
	~Matrix();

	void identity();

	bool isSquare();
	static bool canAdd(const Matrix& right, const Matrix& left);
	static bool canMultiply(const Matrix& right, const Matrix& left);
	bool indexOutRange(int row, int column) const;

	void set(int row, int column, double data);
	const double get(int row, int column) const;
	double& value(int row, int column);

	//OPERATOR OVERLOADING
	friend std::ostream& operator<<(std::ostream& left, const Matrix& right);
	friend const Matrix operator+(const Matrix& right, const Matrix& left);
	friend const Matrix operator-(const Matrix& right, const Matrix& left);
	friend const Matrix operator*(double scalar, const Matrix& matrix);
	friend const Matrix operator*(const Matrix& right, const Matrix& left);



	void somefunction();
};

