#include "stdafx.h"

class Bitmap_Operations
{

public:
	Bitmap_Operations(){}
	
	~Bitmap_Operations(){}
	//initializing of buffers, must be done before all other operations
	// num is the number of buffers that will be used
    void Initialize_Buffers(HWND handle,int num);
	//prepares buffer[which] (1st index is 0) for following operations 
	void Create_Buffer( int which);
	//frees the resources of buffer[which] (1st index = 0)
	void Free_Buffer(int which);
	//frees all resources that have been allocated 
    void Free_Buffers(); 
	//Copies an area from a buffer (=rectangle coordinates->arguments 3-6)
	// to a buffer (coordinates ->arguments 7,8) 
	void Copy_Area_from_to(int frombuf, int tobuf,
	               int top_from_x, int top_from_y, int width, int height,
				   int top_to_x, int top_to_y);
	//Similar to Copy_Area_from_to,Copies an area from a buffer to the screen 
	void Copy_Area_to_Screen(int frombuf,
				   int top_from_x, int top_from_y, int width, int height,
				   int top_to_x, int top_to_y); 
	// Copies whole content of buffer[which] to screen
	void Copy_to_Screen(int which);
    // returns number of buffers
    int Num_of_Buffers(); 
	// Copies an area defined by rect_from (RECT structure) and an handle (h_from)
	// to the buffer[which]
    void Copy_Surface_to_Buffer(HWND h_from, RECT rect_from, int which);
	HDC & Get_HDC();
	HDC & Get_DC_Buffer(int which);
	 
protected:
	HDC my_DC;
	HDC *my_DC_Buffer;
	HWND my_handle;
	RECT *dc_rect;
	HBITMAP  *hbm_Buffer;
	HBITMAP *hbm_oldBuffer;
        int num_buf;
   
};

void Bitmap_Operations::Initialize_Buffers(HWND handle,int num)
{
  my_DC_Buffer = new HDC[num];
  dc_rect = new RECT[num];
  hbm_Buffer = new HBITMAP[num];
  hbm_oldBuffer = new HBITMAP[num];
  my_handle = handle;
  num_buf = num;  
}
int Bitmap_Operations::Num_of_Buffers()
{
  return num_buf;
}
void Bitmap_Operations::Create_Buffer( int which)
{
	GetClientRect(my_handle,&dc_rect[which]);
    my_DC = GetDC(my_handle);
    my_DC_Buffer[which] = CreateCompatibleDC(my_DC);
	 hbm_Buffer[which] = CreateCompatibleBitmap(my_DC,dc_rect[which].right ,
		 dc_rect[which].bottom );
	 hbm_oldBuffer[which] = (HBITMAP) SelectObject(my_DC_Buffer[which],
		 hbm_Buffer[which]);
}
void Bitmap_Operations::Copy_to_Screen(int which)
{
BitBlt(my_DC,0,0,dc_rect[which].right,dc_rect[which].bottom,my_DC_Buffer[which],0,0,SRCCOPY);
}

void Bitmap_Operations::Copy_Area_to_Screen(int frombuf,int top_from_x, int top_from_y,
										  int width, int height,int top_to_x, int top_to_y)
{
  BitBlt(my_DC,top_to_x,top_to_y,width,height,
	   my_DC_Buffer[frombuf],top_from_x,top_from_y,SRCCOPY);
}

void  Bitmap_Operations::Copy_Area_from_to(int frombuf, int tobuf,int top_from_x, 
										 int top_from_y,int width, int height, 
										 int top_to_x, int top_to_y)
{

	BitBlt(my_DC_Buffer[tobuf],top_to_x,top_to_y,width,height,
	 my_DC_Buffer[frombuf],top_from_x,top_from_y,SRCCOPY);
}

void Bitmap_Operations::Free_Buffer(int which)
{
	num_buf--;
	
    SelectObject(my_DC_Buffer[which], hbm_oldBuffer[which]);
 		DeleteDC(my_DC_Buffer[which]);
       DeleteObject(hbm_Buffer[which]); 
	if(num_buf == 0)
	ReleaseDC(my_handle,my_DC);
}
void Bitmap_Operations::Free_Buffers()
{
   for(int i =0 ; i < num_buf ; i++)
   {
      SelectObject(my_DC_Buffer[i], hbm_oldBuffer[i]);
 		DeleteDC(my_DC_Buffer[i]);
       DeleteObject(hbm_Buffer[i]); 
   }
   ReleaseDC(my_handle,my_DC);
}
void Bitmap_Operations::Copy_Surface_to_Buffer(HWND h_from,RECT rect_from,int which)
{
 
  HDC hDC_from;
 //  HWND dt_handle = GetDesktopWindow();//Handle für desktop
 // GetWindowRect(h_from, &rect_from);
  hDC_from = GetDC(0);
  BitBlt(my_DC_Buffer[which],0,0,rect_from.right,rect_from.bottom,hDC_from,0,0,
	  SRCCOPY);
  ReleaseDC(h_from,hDC_from);  
}
HDC & Bitmap_Operations::Get_HDC()
{
	return my_DC;
}

HDC & Bitmap_Operations::Get_DC_Buffer(int which)
{
   return my_DC_Buffer[which];
}
//END of Bitmap_operations Class members