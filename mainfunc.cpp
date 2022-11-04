#include"mainfunc.h"
//
using namespace std;
//
data du_lieu;// du lieu lay tu cau truc data
// khung long khi nhay
string khung_long[9]=  
{
"         ��������",
"         ��������",
"         ��������",
"�       �������� ",
"���  ���������� ",
"������������  �",
"  ��������� �  ",
"�����   �����",
};
////
string dino_die="        ��X�����";
//
string space   = "                 ";
////
void in_diem(){
	
	GOTOXY(100,3);cout<<"SCORE:";
	GOTOXY(106,3);cout<<"0";
	GOTOXY(107,3);cout<<"0";
	GOTOXY(108,3);cout<<"0";
	GOTOXY(109,3);cout<<"0";
}
////
void ghi_diem(){
	
	GOTOXY(100,3);cout<<"SCORE:";
	GOTOXY(106,3);cout<<(du_lieu.score%10000)/1000;
	GOTOXY(107,3);cout<<(du_lieu.score%1000)/100;
	GOTOXY(108,3);cout<<(du_lieu.score%100)/10;
	GOTOXY(109,3);cout<<(du_lieu.score%10);
}
////
DINO::DINO(){
	
	this->xdino=15;
	this->ydino=17;
	this->h=8;
}
////
DINO::~DINO(){	
}
////
void DINO::drawdino_up_down(int x,int y){
    
	for(int i=0;i<8;i++){
		GOTOXY(x,y+i);
		cout<<khung_long[i]<<endl;
   }
}
////
void DINO::drawdino(int x,int y){
	
	static int foot=0;// 
	
	Color(7);
    GOTOXY(x,y);  cout<<"         ��������";
    GOTOXY(x,y+1);cout<<"         ��������";
    GOTOXY(x,y+2);cout<<"         ��������";
    GOTOXY(x,y+3);cout<<"�       �������� ";
    GOTOXY(x,y+4);cout<<"���  ����������  ";
    GOTOXY(x,y+5);cout<<"������������  � ";
    GOTOXY(x,y+6);cout<<"  ���������     ";
    GOTOXY(x,y+7);
    if (foot < 2) {
     	
     		cout<<"   ����  ���    ";
            GOTOXY(x+5,y+8);
            cout<<"��";
            foot++;
       }
    else if (foot >= 2) {
	    		cout<<"    ��� ��      ";
                GOTOXY(x+9,y+8);
                cout<<"��";
                foot++;
				if(foot==4) foot=0;			
		}
}
////
int DINO::get_x(){
	return xdino;
}
int DINO::get_y(){
	return ydino;
}
int DINO::get_h(){
	return h;
}
//
Ground::Ground():DINO(){
	this->xdat=1;
	this->ydat=ydino+h;
}
Ground::~Ground(){	
}
void Ground::taodat(int i){
	
	int v=rand()%(18-1+1)+1;
	
	switch (v){
		case 1:
			ground[1][i]='.';
			ground[2][i]=' ';
		    break;
		case 3:
			ground[1][i]='`';
			ground[2][i]=' ';
		    break;
		case 4:
			ground[1][i]=248;
			ground[2][i]=' ';
			break;
		case 7:
			ground[1][i]=' ';
			ground[2][i]='.';
		     break;
		default:
			ground[1][i]=' ';
			ground[2][i]=' ';
			break;										
	}
}
////
void Ground::khoitaomatdat(){
	for(int i=0;i<sl_ground;i++){
		ground[0][i]='_';
		taodat(i);
	}
	//mat dinh cac ki tu ket thuc o moi hang
	ground[0][sl_ground]='\0';/*  ki tu ket thuc */
	ground[1][sl_ground]='\0';
	ground[2][sl_ground]='\0';
}
//
void Ground::drawdat(){

	for(int i=0;i<3;i++){
		GOTOXY(xdat,ydat+i);
		cout<<ground[i];
	}
}
//
void Ground::di_chuyen(){
	//doi
     Color(7);	    
	for(int i=0;i<sl_ground-1;i++){
		ground[1][i]=ground[1][i+1];
		ground[2][i]=ground[2][i+1];
	}
	taodat(sl_ground-1);
	drawdat();
}
////
VC::VC():Ground(){
	this->x_VC=105;
	this->x_Bird=101;
	this->y_Vc=ydat-5;
	this->y_Bird= ydat-7;
}
////
VC::~VC(){
}
//
string bird_up[5]={  	
"     �    ",	   
" ��� ���  ",
"����������..",
"   ������ ",
"          "
};
//
string bird[5]={
"          ",	
" ���      ",
"����������..",
"   ������ ",
"    ���   "
};
//
void VC::draw_bird(int x){
	   
		if (du_lieu.check_dap<5){
     	    for(int i=0;i<5;i++){
       	  	   GOTOXY(x,y_Bird+i);
       	  	   cout<<bird_up[i];
			 }
			 du_lieu.check_dap++;
       }
       	else if (du_lieu.check_dap >=5) {
       	  for(int i=0;i<5;i++){
       	  	   GOTOXY(x,y_Bird+i);
       	  	   cout<<bird[i];
			 }
			 du_lieu.check_dap++;
			 if(du_lieu.check_dap==10) du_lieu.check_dap=0;
		}
}
void VC::clear_bird(int x_b){
	for(int i=0;i<5;i++){
		GOTOXY(x_b+13,y_Bird+i);
			cout<<" ";		
	}
}
//
void VC::xoa(int a[],int &n, int vt) {
    for(int i = vt; i < n -1; i++){
        a[i] = a[i+1]; 
    }
    n--;  
}
//
void VC::draw_new_bird(int b[],int &n_b){
	if(b[0]==xdat){
		xoa(b,n_b,0);
		for(int i=0;i<13;i++){
			clear_bird(xdat-i);
		}
	}
	for(int i=0;i<n_b;i++){
		draw_bird(b[i]);
		clear_bird(b[i]);
		b[i]--;
		;
	}
}
//
string nha[6]={
"   ���� ",
"�  ���� ",
"�� ���� �",
"���������",
" ������� ",
"   ���� "
};
//
void VC::draw_VC(int x){
    for(int i = 0; i < 6; i++){
        GOTOXY(x, y_Vc + i);
        cout << nha[i];
    }
}
//
void VC::clear_VC(int x_vc){
	for(int i=0;i<6;i++){
		GOTOXY(x_vc+10,y_Vc+i);
			cout<<" ";		
	}
}
//
void VC::draw_new_tree(int toa_nha[],int &n_vc){
	
	if(toa_nha[0]==xdat){
		xoa(toa_nha,n_vc,0);
		for(int i=0;i<11;i++){
			clear_VC(xdat-i);
		}
	}
	for(int i=0;i<n_vc;i++){
		draw_VC(toa_nha[i]);
		clear_VC(toa_nha[i]);
		toa_nha[i]--;
	
	}
}
//
void VC::draw_vc(int tree[],int &n_vc, int bird[],int n_bird){
	if(n_vc<20){
		draw_new_tree(tree,n_vc);
	}
	else{
		n_vc=0;
		draw_new_bird(bird,n_bird);
	}
	
}
//
bool VC::check_cham(int x_vc, int x_b, int x, int y){
	// toa do dino
	int xchan_trai , xchan_phai ;
    int ychan = y + 5 ; 
    
    int x_b_max= x_b + 10;// toa do cuoi cua chim
    int x_vc_max = x_vc + 10; // toa do cuoi cua tree
  
    if(du_lieu.kt_jump==true){// neu khung long dang nhay toa se thay doi
    	xchan_phai=x+9;
    	xchan_trai=x+3;
    }
    else{ 
    	xchan_phai=x+13;
    	xchan_trai=x+1;
	}
	// check tao do cua dino vs tree
	if((xchan_phai >= x_vc && xchan_phai <= x_vc_max) || (xchan_trai >= x_vc && xchan_trai <= x_vc_max)){
        if((ychan >= y_Vc && ychan <= ydat)){
            return true;
        }
    }
    // check toa do dino vs con chim
    else if((xchan_trai >= x_b+1 && xchan_trai <= x_b_max) || (xchan_phai >= x_b+1 && xchan_phai <= x_b_max)){
    	if((ychan >= (y_Bird+1) && ychan <= ydat)){
    		return true;
		}
	}
    return false;
}
//
bool VC::GameOver(int x, int y, int toa_nha[],int bird[], int n_vc){
	for(int i=0; i<n_vc; i++){
		if(check_cham(toa_nha[i], bird[i], x, y)){// neu nhu true thi dino die 
			GOTOXY(x+1, y+1);
			cout<< dino_die;
			return true;
		}
	}
	return false;
}

void game_over(){
		Color(4);
		GOTOXY(55,10);
		cout<<"YOU DIE!";
		GOTOXY(47,11);
		cout<<"an cach de quay lai menu";
		Color(7);
        du_lieu.score=0;
}
//
int Random(int a,int b){//ham tao ra mot gia tri ngau nhien
	return a + rand()%(b-a+1);
}
////
void ingame(){

//	//khaai bao ra mot con dino moi 
    DINO *dino = new DINO();
    dino->drawdino(dino->get_x(),dino->get_y());
//   //khai bao mat dat
	Ground *dat=new Ground();
    dat->khoitaomatdat();
    dat->drawdat();
    //khai vao vat can
	VC *vc=new VC();
    //
    in_diem();
    int check=0;//0 dung im , 1 nhay, 2 xuong
    //lay gia tri toa do
	int x=dino->get_x();
    int y=dino->get_y(); 
    int ch_cao=dino->get_h(); 
    
    //bien dem
    int ct;
    int DD=0;
    int count=0,count1=0,count2=250;// kiem soat toc do in vc
    int dem=0;
    
    int n_vc=0,n_bird=0;// n vat can
    int t1=100,t2=100;// khoang gia tri de in cay
    
    //  cap phat phat bo nho
    int *tree = new int[n_vc];
    int *bird = new int[n_bird];
	while(1){
		
		//
		dat->di_chuyen();
	    //co che tinh diem
	    dem++;
	    if(dem>30){
	        du_lieu.score++;
	        ghi_diem();
	        dem=0;
	        DD++;
	        // toc do se tang neu 
	        if(DD==15){
	    	    if(du_lieu.speed>12){
	    		    du_lieu.speed-=3;
	    	        DD=0;   
			    }
		    }   
	    }
		//
	    if(count1==0){
	    	tree[n_vc++]=vc->get_xvc();// tang n vat can
			count1=Random(t1,t2);// random [60-100] 
		}
		vc->draw_new_tree(tree,n_vc);
		// in con chim
        if(count2==0){
			count2=50;
			bird[n_bird++]=vc->get_xbird(); //count=0;
		}
		
		vc->draw_new_bird(bird,n_bird);
		vc->draw_new_bird(bird,n_bird);
        //
        if(vc->GameOver(x,y,tree,bird,n_vc)==true){
	    	du_lieu.check_die=true;
	    	// am thanh khi chet
	    	PlaySound(TEXT("D:\\code btl-20220502T075706Z-001\\code btl 3\\code btl 3\\dino2.wav"),NULL,SND_FILENAME);
		}
		//
		if(du_lieu.check_die==true){//  check die = true => chet
			du_lieu.check_die=false;
		     game_over();
			// sau khi chet thi thoat khoi vong lap
			break;
		}
		//
       // dieu khien
         if(kbhit()){
	           char c=getch();  
         if(c==-32){
	        	c=getch();
	        	if(c==72&&check==0){//neu nhu an phim mui ten va dino o mat dat thi cho check =1 
	        	// am thanh khi nhay
	        //	PlaySound(TEXT("D:\\code btl-20220502T075706Z-001\\code btl 3\\code btl 3\\dino1.wav"),NULL,SND_FILENAME);
	        	 check=1;du_lieu.kt_jump=true;
				}
		    }
	    }
		// kiem tra va ve lai khung long khi nhay
		if(check==1){// khi check la nhay thi in ra dino o trang thai nhay
		
            if(y<7){
		    	if((ct%2)==0){
				GOTOXY(x,y+ch_cao-1);
			    cout<<space;
			    y--;
			    dino->drawdino_up_down(x,y);
			   }
			   ct++;
		    }
		    else{
		    	GOTOXY(x,y+ch_cao-1);
			    cout<<space;
			    y--;
			    dino->drawdino_up_down(x,y);
			}	
	    }
		else if(check==2){
		    if(y<5){
		    	if((ct%2)==0){
				   GOTOXY(x,y);
			       cout<<space;
				   y++;
		           dino->drawdino_up_down(x,y); 
			    }
		     ct++;
			}
			else{
				GOTOXY(x,y);
			    cout<<space;
				y++;
		        dino->drawdino_up_down(x,y); 
			}
			
	    }
	    if(y== dino->get_y()-du_lieu.jump){
	    	check=2;
  	      dino->drawdino_up_down(x,y); 
	    }
		else if(y==dino->get_y()){// khi roi xuong toa do y = ydino ban dau thi in dino o mat dat 
 			dino->drawdino(x,y);
			check=0; 	
			du_lieu.kt_jump=false;
	    }
	    // giam bien kiem soat in cay
	    count1--;
	    count2--;
        Sleep(du_lieu.speed);
        
    }
    // xoa bo nho 
	delete dino;
	delete dat;
	delete tree;
	delete bird;
}
