#include <iostream>
#include <math.h>
#include <vector>
#define G 9.81
#define pi 3.141617
using namespace std;

struct Do{
    float d = 800;
    float Ho = 100;
    float Xo = 0;
    float Yo = Ho;
    float d0 = 0.05*d;
};

struct Dd{
    float d = 800;
    float Hd = 20;
    float Xd = d;
    float Yd = Hd;
    float d0 = 0.025*d;
};

void ImprimirResultados1(int angle,int V0o,float x,float y,int t)
{
    cout << "Impacto con un angulo de " << angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << V0o << endl;
    cout << "Impacto con posicion x: " << x << endl;
    cout << "Impacto con posicion y: " << y << endl;
    cout << "Con tiempo: " << t << endl;
    cout << endl;
}

void DisparoOfensivo(Do disparoO,Dd disparoD, int Voo){
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoO.Yo + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoD.Xd - x),2)+pow((disparoD.Yd - y),2)) < disparoO.d0){
                    if(y<0) y = 0;
                    ImprimirResultados1(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void DisparoDefensivo(Do disparoO,Dd disparoD, int Voo){
    int flag = 0;
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = disparoD.Yd + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoO.Xo - x),2)+pow((disparoO.Yo - y),2)) < disparoD.d0){
                    if(y<0) y = 0;
                    ImprimirResultados1(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void DisparoDefensivo2(Do disparoO,Dd disparoD, int Voo,int angleoo,int Vooo){
    int flag = 0;
    float x,y,x2,y2;
    float Vxo,Vy0, Vxoo,Vyoo;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    Vxoo = Vooo*cos((angleoo)*pi/180);
    Vyoo = Vooo*sin((angleoo)*pi/180);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t+2);
                y2 = disparoO.Yo + Vyoo*(t+2) -(0.5*G*(t+2)*(t+2));
                x = disparoD.Xd+Vxo*t;
                y = disparoD.Yd + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoD.d0){
                    if(y<0) y = 0;
                    ImprimirResultados1(angleoo,Vooo,x2,y2,t+2);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados1(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

void DisparoDefensivo3(Do disparoO,Dd disparoD, int Voo,int angleoo,int Vooo){
    int flag = 0;
    bool flag2 = 0;
    float x,y,x2,y2;
    float aux,auy;
    float Vxo,Vy0, Vxoo,Vyoo;
    int V0o = 0;
    int t = 0;
    int angle = 0;
    Vxoo = Vooo*cos((angleoo)*pi/180);
    Vyoo = Vooo*sin((angleoo)*pi/180);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle+90)*pi/180);
            Vy0 = V0o*sin((angle+90)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t+2);
                y2 = disparoO.Yo + Vyoo*(t+2) -(0.5*G*(t+2)*(t+2));
                x = disparoD.Xd+Vxo*t;
                y = disparoD.Yd + Vy0*t -(0.5*G*t*t);
                for(int t2 = t; ;t2++){
                    aux = disparoD.Xd+Vxo*t2;
                    auy = disparoD.Yd + Vy0*t2 -(0.5*G*t2*t2);
                    if(sqrt(pow((disparoO.Xo - aux),2)+pow((disparoO.Yo - auy),2)) < disparoD.d0){
                        flag2 = 1;
                        break;
                    }
                    if(auy < 0){
                        break;
                    }
                }
                if(flag2){
                    flag2 = 0;
                    break;
                }
                if(sqrt(pow((disparoD.Xd - x2),2)+pow((disparoD.Yd - y2),2)) < disparoO.d0){
                    break;
                }
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < disparoD.d0){
                    if(y<0) y = 0;
                    ImprimirResultados1(angleoo,Vooo,x2,y2,t+2);
                    cout << "_________________________________"<<endl;
                    ImprimirResultados1(angle, V0o, x, y, t);
                    flag += 1;
                    V0o += 50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag == 3) break;

        }
        if(flag == 3) break;
    }
    if(flag != 3){
        cout << "No impacto en los disparos esperados"<< endl;
    }
}

int main()
{
    Do disparoO;
    Dd disparoD;
    int Voo;
    cout << "Ingrese Vo desde la cual quiere probar: " << endl;
    cin >> Voo;
    DisparoOfensivo(disparoO, disparoD, Voo);
    DisparoDefensivo(disparoO, disparoD, Voo);
    DisparoDefensivo2(disparoO,disparoD,Voo,31,85);
    DisparoDefensivo3(disparoO,disparoD,Voo,31,85);

    return 0;
}
