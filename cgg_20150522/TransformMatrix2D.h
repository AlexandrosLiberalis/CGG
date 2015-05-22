#ifndef TRANSFORMMATRIX2D_H_
#define TRANSFORMMATRIX2D_H_

// TransformMatrix2D is a 3x3 Matrix used for 2D transformations
//
// - rotation around 0-Point by "theta" degree (not radiant)
// - translation by x/y
// - scale by x-/y-times
// - mirror along x-/y-axis
//
// We ignore M + M and M - M (not needed in our guides)
// We use M * M and M * v (Vector2D)
//
// in Mathtools.h we define methods to directly create one of the
// 4 transformation matrices

class Vector2D;

class TransformMatrix2D
{
private:
	// 3x3 matrix k_[row][column]
	double k_[3][3];

	// unit matrix for initialization a new matrix before setting values
	void unitMatrix();
public:
	TransformMatrix2D();
	TransformMatrix2D(const TransformMatrix2D &src);
	virtual ~TransformMatrix2D();

	// getter and setter (at the same time)
	// usage: M.at(r,c) = number

	double& at(const int row, const int col);

	// transformation matrix types
	// only one possible, but can be combined with multiplication

	void translate(double tx = 0.0, double ty = 0.0);
	void scale(double sx = 1.0, double sy = 1.0);
	void rotate(double theta = 0.0);
	void mirror(bool x_axis = false, bool y_axis = false);

	// operator overloading

	friend TransformMatrix2D operator*(TransformMatrix2D &M1, TransformMatrix2D &M2);
	friend Vector2D operator*(TransformMatrix2D &M, Vector2D &v);
};

#endif