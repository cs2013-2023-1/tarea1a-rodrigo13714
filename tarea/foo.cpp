#include "foo.h"
#include <iomanip>

Matriz2D::Matriz2D(){
    // Constructor por defecto

    this->filas=3;
    this->columnas=3;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
    }
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            ptr[i][j] = rand() % 11/10.0;
        }
    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    this->filas=n;
    this->columnas=n;
    ptr = new float*[n];
    for(int i = 0; i < n; i++){
        ptr[i] = new float[n];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ptr[i][j] = rand() % 11/10.0;
        }
    }

}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    this->filas=n;
    this->columnas=m;
    ptr = new float*[n];
    for(int i = 0; i < n; i++){
        ptr[i] = new float[m];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ptr[i][j] = rand() %11/10.0;
        }
    }

}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    ptr = new float*[m.filas];
    for(int i = 0; i < m.filas; i++){
        ptr[i] = new float[m.columnas];
    }
    for(int i = 0; i < m.filas; i++){
        for(int j = 0; j < m.columnas; j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }
    filas=m.filas;
    columnas=m.columnas;
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    this->filas = m.filas;
    columnas = m.columnas;
    m.columnas = 0;
    ptr = new float*[filas];
    for(int i = 0; i < filas; i++){
        ptr[i] = new float[columnas];
    }
    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            ptr[i][j] = m.ptr[i][j];
        }
    }
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D result(m.columnas,m.filas);
    for (int i = 0; i < m.columnas; i++)
    {
        for (int j = 0; j < m.filas; j++)
        {
            result.ptr[i][j]=m.ptr[j][i];
        }
    }
    return result;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<

    for (int i = 0; i < m.filas; i++)
    {
        for (int j = 0; j < m.columnas; j++)
        {
            os << setw(4) << m.ptr[i][j];
        }
        os << endl;
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +

    if ((m1.filas==m2.filas)&&(m1.columnas==m2.columnas)) {
        Matriz2D result(m1.filas,m1.columnas);
        for (int i = 0; i < m1.filas; i++) {
            for (int j = 0; j < m1.columnas; j++) {
                result.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];
            }
        }
        return result;
    }

}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    
    if ((m1.filas==m2.filas)&&(m1.columnas==m2.columnas)) {
        Matriz2D result(m1.filas,m1.columnas);
        for (int i = 0; i < m1.filas; i++) {
            for (int j = 0; j < m1.columnas; j++) {
                result.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];
            }
        }
        return result;
    }
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    
    if ((m1.filas==m2.filas)&&(m1.columnas==m2.columnas)) {
        Matriz2D result(m1.filas,m1.columnas);
        for (int i = 0; i < m1.filas; i++) {
            for (int j = 0; j < m1.columnas; j++) {
                result.ptr[i][j] = m1.ptr[i][j] * m2.ptr[i][j];
            }
        }
        return result;
    }

}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D result(m.filas,m.columnas);
    for (int i=0;i<m.filas;i++){
        for (int j=0;j<m.columnas;j++){
            result.ptr[i][j]=m.ptr[i][j] + n;
        }
    }
    return result;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D result(m.filas,m.columnas);
    for (int i=0;i<m.filas;i++){
        for (int j=0;j<m.columnas;j++){
            result.ptr[i][j]=m.ptr[i][j] + n;
        }
    }
    return result;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D result(m.filas,m.columnas);
    for (int i=0;i<m.filas;i++){
        for (int j=0;j<m.columnas;j++){
            result.ptr[i][j]=m.ptr[i][j] * n;
        }
    }
    return result;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D result(m.filas,m.columnas);
    for (int i=0;i<m.filas;i++){
        for (int j=0;j<m.columnas;j++){
            result.ptr[i][j]=m.ptr[i][j] / n;
        }
    }
    return result;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}