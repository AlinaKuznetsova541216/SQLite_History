//---------------------------------------------------------------------------

#ifndef KuznetsovaH
#define KuznetsovaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
//#include "VirtualTreesD.hpp"
#include "VirtualTrees.hpp"
//#include "VirtualTrees.hpp"
//#include "VirtualTrees.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TVirtualStringTree *VirtualStringTree1;
	TButton *Button2;
	TEdit *Edit1;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall VirtualStringTree1NodeClick(TBaseVirtualTree *Sender, const THitInfo &HitInfo);




private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
