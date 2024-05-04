#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

class Figure abstract {
protected:
    int tetr[4][4];
    int color[3];
    string name;
public:
    virtual ~Figure() {}
    virtual void SetGeometry(int a[4][4]) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                tetr[i][j] = a[i][j];
            }
        }
    }
    virtual void SetColor(int r, int g, int b) {
        color[0] = r;
        color[1] = g;
        color[2] = b;
    }
    virtual void SetName(string figureName) {
        name = figureName;
    }
    virtual void Print() {
        cout << "Figure: " << name << endl;
        cout << "Color (RGB): " << color[0] << ", " << color[1] << ", " << color[2] << endl;
        cout << "Geometry: " << endl;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                cout << tetr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Figure_1 : public Figure {
public:
    Figure_1() {
        int a[4][4] = {
            {1, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(249, 255, 1);
        SetName("Figure_1");
    }
};

class Figure_2 : public Figure {
public:
    Figure_2() {
        int a[4][4] = {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(0, 229, 255);
        SetName("Figure_2");
    }
};

class Figure_3 : public Figure {
public:
    Figure_3() {
        int a[4][4] = {
            {0, 1, 1, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(246, 1, 0);
        SetName("Figure_3");
    }
};

class Figure_4 : public Figure {
public:
    Figure_4() {
        int a[4][4] = {
            {1, 1, 0, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(104, 182, 36);
        SetName("Figure_4");
    }
};

class Figure_5 : public Figure {
public:
    Figure_5() {
        int a[4][4] = {
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(255, 140, 5);
        SetName("Figure_5");
    }
};

class Figure_6 : public Figure {
public:
    Figure_6() {
        int a[4][4] = {
            {0, 1, 0, 0},
            {0, 1, 0, 0},
            {1, 1, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(254, 81, 188);
        SetName("Figure_6");
    }
};

class Figure_7 : public Figure {
public:
    Figure_7() {
        int a[4][4] = {
            {1, 1, 1, 0},
            {0, 1, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        };
        SetGeometry(a);
        SetColor(159, 0, 152);
        SetName("Figure_7");
    }
};

class Creator abstract {
public:
    virtual Figure* Create() = 0;
};

class FigureCreator1 : public Creator {
public:
    Figure* Create() override {
        return new Figure1;
    }
};

class FigureCreator2 : public Creator {
public:
    Figure* Create() override {
        return new Figure_2;
    }
};

class FigureCreator3 : public Creator {
public:
    Figure* Create() override {
        return new Figure_3;
    }
};

class FigureCreator4 : public Creator {
public:
    Figure* Create() override {
        return new Figure_4;
    }
};

class FigureCreator5 : public Creator {
public:
    Figure* Create() override {
        return new Figure_5;
    }
};

class FigureCreator6 : public Creator {
public:
    Figure* Create() override {
        return new Figure_6;
    }
};

class FigureCreator7 : public Creator {
public:
    Figure* Create() override {
        return new Figure_7;
    }
};

Figure* Client(Creator* pDev) {
    return pDev->Create();
}

int main() {
    Creator* pDev = new FigureCreator1();
    Figure* pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new FigureCreator2();
    pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new FigureCreator3();
    pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new FigureCreator4();
    pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new FigureCreator5();
    pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new FigureCreator6();
    pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    cout << endl;

    pDev = new FigureCreator7();
    pHouse = Client(pDev);
    pHouse->Print();
    delete pHouse;
    delete pDev;

    return 0;
}