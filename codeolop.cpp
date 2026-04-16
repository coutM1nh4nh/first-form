#include <iostream>
#include <cmath>
using namespace std;

class Diem{
    private:
    float x,y;
    public:

    Diem(float _x=0, float _y=0){
         x=_x;
         y=_y;
    }

    void Nhap(){
        cout<<"Nhap x: ";
        cin>>x;
        cout<<"Nhap y: ";
        cin>>y;
    }
    
    float getX(){
        return x;
    }

    float getY(){
        return y;
    }

    void setX(float _x){
        x=_x;
    }
    void setY(float _y){
        y=_y;
    }

    void TinhTien(float dx,float dy){
        x +=dx;
        y +=dy;
    }

    void Xuat(){
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    
    void quay(float gocRad){
        float x_new = x*cos(gocRad)-y*sin(gocRad);
        float y_new = x*cos(gocRad)+y*cos(gocRad);
        x=x_new;
        y=y_new; 
    }

    void Change(float k){
        x *=k;
        y *=k;
    }


};

class cDaGiac{
 int soDinh;
 Diem* dinh;
 public:
 cDaGiac() {
  
}

cDaGiac(const cDaGiac& d) {
  soDinh = d.soDinh;
  dinh = new Diem[soDinh];
  for (int i = 0; i < soDinh; ++i)
      dinh[i] = d.dinh[i];
}

~cDaGiac(){
  delete[] dinh;
}

void Nhap(){
  cout<<"Nhap so dinh cua da giac la: ";
  cin>>soDinh;
  delete[] dinh;
  dinh = new Diem[soDinh];
  for(int i=0;i<soDinh;i++){
    cout<<"So diem thu "<<i+1<<": ";
    dinh[i].Nhap();
  }
}

void TinhTien(float dx, float dy){
  for(int i=0;i<soDinh;i++){
    dinh[i].TinhTien(dx, dy);
  }
}

void Quay(float gocDo){
  float gocRad=gocDo*3.14/180;
   for(int i=0;i<soDinh;i++){
    dinh[i].quay(gocDo);
   }
}

void change(float k){
  for(int i=0;i<soDinh;i++){
    dinh[i].Change(k);
  }
}
};

int main(){
     cDaGiac ABCD;
     ABCD.Nhap();

     
}