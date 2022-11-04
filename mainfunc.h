#include<iostream>
#include<conio.h>
#include"Do hoa.h"
#include<fstream>
#include <ctime>
#include<MMsystem.h>
//
#pragma comment (lib, "winmm.lib")
#define sl_ground 117
//
class DINO{
	protected:// tinh dong goi
		int xdino;
        int ydino;
        int h;
    public:
	    DINO();
	    ~DINO();
	    // tinh truu tuong
	    int get_x();
		int get_y();
		int get_h();
		
	   virtual void drawdino(int x,int y);
	    void drawdino_up_down(int x,int y);
		void dino_up_down(int x,int &y,int ch); 
		
		
};
//
class Ground: public DINO{// tinh ke thua
	protected:
		int xdat;
		int ydat;
		char ground[3][sl_ground+1];
	public:
	    Ground();
		~Ground();
		
		void draw();
	    void taodat(int i);
		void khoitaomatdat();
		void di_chuyen();
				
};
//
class VC: public Ground{
	protected:
		int x_VC;
		int x_Bird;
		int y_Vc;
		int y_Bird;
	public:
	    VC();
		~VC();
		
		int get_xvc(){
			return x_VC;
		}
		int get_xbird(){
			return x_Bird;
		}
		int get_yvc(){
			return y_Vc;
		}
		int get_ybird(){
			return y_Bird;
		}
		
		void draw_VC(int x);
		void draw_bird(int x);
		void clear_bird(int x);
		void clear_VC(int x);
		bool check_cham(int x_vc,int x_b, int x,int y);
		void xoa(int a[],int &n, int vt);
		void draw_new_bird(int vc[],int &n_vc);
		void draw_new_tree(int toa_nha[],int &n_vc);
		void draw_vc(int tree[],int &n_vc, int bird[],int n_bird);
		bool GameOver(int x, int y, int t[], int b[], int n_vc);
		
};
//
typedef struct{
	int score=0;
    int speed=24 ;
    int jump=14;// lay ydino - jump = gioi han nhay 
    bool kt_jump=false;// kiem tra nhay
    bool check_die=false;// kiem tra die
    int check_dap=0;
    
} data;
//
int Random(int a,int b);
void in_diem();
void ghi_diem();
void ingame();

