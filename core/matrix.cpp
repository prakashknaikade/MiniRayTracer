#include <core/matrix.h>
#include <core/assert.h>

#include <core/vector.h>
#include <core/point.h>

namespace rt {

Matrix::Matrix(const HomogeneousCoord& r1, const HomogeneousCoord& r2, const HomogeneousCoord& r3, const HomogeneousCoord& r4) {
    /* TODO */
    this->matRow[0] = r1;
    this->matRow[1] = r2;
    this->matRow[2] = r3;
    this->matRow[3] = r4;
}

HomogeneousCoord& Matrix::operator[](int idx) {
    /* TODO */ 
    rt_assert(idx>=0);
    rt_assert(idx<=3);
    return(matRow[idx]);
}

HomogeneousCoord Matrix::operator[](int idx) const {
    /* TODO */ 
    rt_assert(idx>=0);
    rt_assert(idx<=3);
    return(matRow[idx]);
}

Matrix Matrix::operator+(const Matrix& b) const {
    /* TODO */
    return Matrix(this->matRow[0] + b[0], this->matRow[1] + b[1], this->matRow[2] + b[2], this->matRow[3] + b[3]);
} 


Matrix Matrix::operator-(const Matrix& b) const {
    /* TODO */ 
    return Matrix(this->matRow[0] - b[0], this->matRow[1] - b[1], this->matRow[2] - b[2], this->matRow[3] - b[3]);

}

Matrix Matrix::transpose() const {
    /* TODO */ 
    Matrix result;
    result[0] = HomogeneousCoord(this->matRow[0][0], this->matRow[1][0], this->matRow[2][0], this->matRow[3][0]);
    result[1] = HomogeneousCoord(this->matRow[0][1], this->matRow[1][1], this->matRow[2][1], this->matRow[3][1]);
    result[2] = HomogeneousCoord(this->matRow[0][2], this->matRow[1][2], this->matRow[2][2], this->matRow[3][2]);
    result[3] = HomogeneousCoord(this->matRow[0][3], this->matRow[1][3], this->matRow[2][3], this->matRow[3][3]);
    return result;
}

Matrix Matrix::invert() const {
    Matrix result;
    const Matrix& m = *this;

    // Taken and modified from http://stackoverflow.com/questions/1148309/inverting-a-4x4-matrix
    result[0][0] =  m[1][1] * m[2][2] * m[3][3] - m[1][1] * m[2][3] * m[3][2] - m[2][1] * m[1][2] * m[3][3] + m[2][1] * m[1][3] * m[3][2] + m[3][1] * m[1][2] * m[2][3] - m[3][1] * m[1][3] * m[2][2];
    result[1][0] = -m[1][0] * m[2][2] * m[3][3] + m[1][0] * m[2][3] * m[3][2] + m[2][0] * m[1][2] * m[3][3] - m[2][0] * m[1][3] * m[3][2] - m[3][0] * m[1][2] * m[2][3] + m[3][0] * m[1][3] * m[2][2];
    result[2][0] =  m[1][0] * m[2][1] * m[3][3] - m[1][0] * m[2][3] * m[3][1] - m[2][0] * m[1][1] * m[3][3] + m[2][0] * m[1][3] * m[3][1] + m[3][0] * m[1][1] * m[2][3] - m[3][0] * m[1][3] * m[2][1];
    result[3][0] = -m[1][0] * m[2][1] * m[3][2] + m[1][0] * m[2][2] * m[3][1] + m[2][0] * m[1][1] * m[3][2] - m[2][0] * m[1][2] * m[3][1] - m[3][0] * m[1][1] * m[2][2] + m[3][0] * m[1][2] * m[2][1];

    float det = m[0][0] * result[0][0] + m[0][1] * result[1][0] + m[0][2] * result[2][0] + m[0][3] * result[3][0];
    if (det == 0)
        return Matrix::zero();

    result[0][1] = -m[0][1] * m[2][2] * m[3][3] + m[0][1] * m[2][3] * m[3][2] + m[2][1] * m[0][2] * m[3][3] - m[2][1] * m[0][3] * m[3][2] - m[3][1] * m[0][2] * m[2][3] + m[3][1] * m[0][3] * m[2][2];
    result[1][1] =  m[0][0] * m[2][2] * m[3][3] - m[0][0] * m[2][3] * m[3][2] - m[2][0] * m[0][2] * m[3][3] + m[2][0] * m[0][3] * m[3][2] + m[3][0] * m[0][2] * m[2][3] - m[3][0] * m[0][3] * m[2][2];
    result[2][1] = -m[0][0] * m[2][1] * m[3][3] + m[0][0] * m[2][3] * m[3][1] + m[2][0] * m[0][1] * m[3][3] - m[2][0] * m[0][3] * m[3][1] - m[3][0] * m[0][1] * m[2][3] + m[3][0] * m[0][3] * m[2][1];
    result[3][1] =  m[0][0] * m[2][1] * m[3][2] - m[0][0] * m[2][2] * m[3][1] - m[2][0] * m[0][1] * m[3][2] + m[2][0] * m[0][2] * m[3][1] + m[3][0] * m[0][1] * m[2][2] - m[3][0] * m[0][2] * m[2][1];
    result[0][2] =  m[0][1] * m[1][2] * m[3][3] - m[0][1] * m[1][3] * m[3][2] - m[1][1] * m[0][2] * m[3][3] + m[1][1] * m[0][3] * m[3][2] + m[3][1] * m[0][2] * m[1][3] - m[3][1] * m[0][3] * m[1][2];
    result[1][2] = -m[0][0] * m[1][2] * m[3][3] + m[0][0] * m[1][3] * m[3][2] + m[1][0] * m[0][2] * m[3][3] - m[1][0] * m[0][3] * m[3][2] - m[3][0] * m[0][2] * m[1][3] + m[3][0] * m[0][3] * m[1][2];
    result[2][2] =  m[0][0] * m[1][1] * m[3][3] - m[0][0] * m[1][3] * m[3][1] - m[1][0] * m[0][1] * m[3][3] + m[1][0] * m[0][3] * m[3][1] + m[3][0] * m[0][1] * m[1][3] - m[3][0] * m[0][3] * m[1][1];
    result[3][2] = -m[0][0] * m[1][1] * m[3][2] + m[0][0] * m[1][2] * m[3][1] + m[1][0] * m[0][1] * m[3][2] - m[1][0] * m[0][2] * m[3][1] - m[3][0] * m[0][1] * m[1][2] + m[3][0] * m[0][2] * m[1][1];
    result[0][3] = -m[0][1] * m[1][2] * m[2][3] + m[0][1] * m[1][3] * m[2][2] + m[1][1] * m[0][2] * m[2][3] - m[1][1] * m[0][3] * m[2][2] - m[2][1] * m[0][2] * m[1][3] + m[2][1] * m[0][3] * m[1][2];
    result[1][3] =  m[0][0] * m[1][2] * m[2][3] - m[0][0] * m[1][3] * m[2][2] - m[1][0] * m[0][2] * m[2][3] + m[1][0] * m[0][3] * m[2][2] + m[2][0] * m[0][2] * m[1][3] - m[2][0] * m[0][3] * m[1][2];
    result[2][3] = -m[0][0] * m[1][1] * m[2][3] + m[0][0] * m[1][3] * m[2][1] + m[1][0] * m[0][1] * m[2][3] - m[1][0] * m[0][3] * m[2][1] - m[2][0] * m[0][1] * m[1][3] + m[2][0] * m[0][3] * m[1][1];
    result[3][3] =  m[0][0] * m[1][1] * m[2][2] - m[0][0] * m[1][2] * m[2][1] - m[1][0] * m[0][1] * m[2][2] + m[1][0] * m[0][2] * m[2][1] + m[2][0] * m[0][1] * m[1][2] - m[2][0] * m[0][2] * m[1][1];

    result = result*(1.0f/det);
    return result;
}

bool Matrix::operator==(const Matrix& b) const {
    /* TODO */ 
    return((matRow[0]==b[0] && matRow[1]==b[1] && matRow[2]==b[2] && matRow[3]==b[3]));
}

bool Matrix::operator!=(const Matrix& b) const {
    /* TODO */ 
    return !((*this) == b);

}

Matrix product(const Matrix& a, const Matrix& b) {
    /* TODO */ 
    Matrix bT = b.transpose();
    Matrix result = Matrix::zero();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result[i][j] = dot(a[i], bT[j]);
        }
    }
    return(result);
}

Matrix operator*(const Matrix& a, float scalar) {
    /* TODO */ 
    return Matrix(a[0] * scalar, a[1] * scalar, a[2] * scalar, a[3] * scalar);
}

Matrix operator*(float scalar, const Matrix& a) {
    /* TODO */ 
    return Matrix(a[0] * scalar, a[1] * scalar, a[2] * scalar, a[3] * scalar);

}

HomogeneousCoord Matrix::operator*(const HomogeneousCoord& b) const {
    /* TODO */ 
    return HomogeneousCoord(dot(matRow[0],b), dot(matRow[1],b), dot(matRow[2],b), dot(matRow[3],b));

}

Vector Matrix::operator*(const Vector& b) const {
    /* TODO */ 
    HomogeneousCoord bHomo = HomogeneousCoord(b);
    return Vector(dot(matRow[0],bHomo), dot(matRow[1],bHomo), dot(matRow[2],bHomo));

}

Point Matrix::operator*(const Point& b) const {
    /* TODO */ 
    HomogeneousCoord p = (*this) * HomogeneousCoord(b);
    return Point(p.x / p.w, p.y / p.w, p.z/ p.w);

}

float Matrix::det() const {
    /* TODO */ //using the invert functions code
    HomogeneousCoord result;
    const Matrix& m = *this;

    result[0] =  m[1][1] * m[2][2] * m[3][3] - m[1][1] * m[2][3] * m[3][2] - m[2][1] * m[1][2] * m[3][3] + m[2][1] * m[1][3] * m[3][2] + m[3][1] * m[1][2] * m[2][3] - m[3][1] * m[1][3] * m[2][2];
    result[1] = -m[1][0] * m[2][2] * m[3][3] + m[1][0] * m[2][3] * m[3][2] + m[2][0] * m[1][2] * m[3][3] - m[2][0] * m[1][3] * m[3][2] - m[3][0] * m[1][2] * m[2][3] + m[3][0] * m[1][3] * m[2][2];
    result[2] =  m[1][0] * m[2][1] * m[3][3] - m[1][0] * m[2][3] * m[3][1] - m[2][0] * m[1][1] * m[3][3] + m[2][0] * m[1][3] * m[3][1] + m[3][0] * m[1][1] * m[2][3] - m[3][0] * m[1][3] * m[2][1];
    result[3] = -m[1][0] * m[2][1] * m[3][2] + m[1][0] * m[2][2] * m[3][1] + m[2][0] * m[1][1] * m[3][2] - m[2][0] * m[1][2] * m[3][1] - m[3][0] * m[1][1] * m[2][2] + m[3][0] * m[1][2] * m[2][1];

    float det = m[0][0] * result[0] + m[0][1] * result[1] + m[0][2] * result[2] + m[0][3] * result[3];
}

Matrix Matrix::zero() {
    /* TODO */ 
    HomogeneousCoord z(0.f, 0.f, 0.f, 0.f);
    return Matrix(z, z, z, z);
}

Matrix Matrix::identity() {
    /* TODO */ 
    HomogeneousCoord row1(1.f, 0.f, 0.f, 0.f);
    HomogeneousCoord row2(0.f, 1.f, 0.f, 0.f);
    HomogeneousCoord row3(0.f, 0.f, 1.f, 0.f);
    HomogeneousCoord row4(0.f, 0.f, 0.f, 1.f);
    return Matrix(r1, r2, r3, r4);
}

Matrix Matrix::system(const Vector& e1, const Vector& e2, const Vector& e3) {
    /* TODO */ 
    return Matrix(HomogeneousCoord(e1), HomogeneousCoord(e2), HomogeneousCoord(e3), HomogeneousCoord(0.f, 0.f, 0.f, 1.f)).transpose();

}

}