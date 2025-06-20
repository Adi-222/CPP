#include<iostream>
using namespace std;

class Vector3D; 

class Vector2D {
private:
    int x, y;

public:
    Vector2D(int x, int y) : x(x), y(y) {}

    friend Vector3D vectorSum(Vector2D v1, Vector3D v2);
};

class Vector3D {
private:
    int x, y, z;

public:
    Vector3D(int x, int y, int z) : x, y, z {}

    friend Vector3D vectorSum(Vector2D v1, Vector3D v2);
};

Vector3D vectorSum(Vector2D v1, Vector3D v2) {
    return Vector3D(v1.x + v2.x, v1.y + v2.y, v2.z);
}

int main() {
    Vector2D v1(2, 2);
    Vector3D v2(3, 3, 3);

    Vector3D sum = vectorSum(v1, v2);

    cout << "Sum of vector is " << sum.x<< sum.y  << sum.z << endl;

    return 0;
}
