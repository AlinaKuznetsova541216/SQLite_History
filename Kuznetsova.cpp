//---------------------------------------------------------------------------
#include "windows.h"
#include <vcl.h>
#pragma hdrstop
#include <locale.h>
#include "Kuznetsova.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma link "VirtualTrees"
#pragma resource "*.dfm"
#include <iostream>
#include "sqlite3.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct
{
	int id;
	UnicodeString name;
   //	AnsiString title;
} MyHistory;


TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
VirtualStringTree1 -> NodeDataSize = sizeof(MyHistory);

}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 VirtualStringTree1 -> Clear();
 setlocale (LC_ALL,"Rus");
 setlocale(0, ".1251");
 using namespace std;
	const char *db_name="D:\\gns\\proj\\SQLite\\History";
	sqlite3 *db;
	char *zErrMsg = 0;
	int error;

	error = sqlite3_open(db_name, &db);
	if ( error )
	{
	   //	cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
		sqlite3_close(db);
	}

	sqlite3_stmt    *result;


	error = sqlite3_prepare_v2(db,"SELECT id, url from urls", -1, &result, NULL);
	if ( error )
	{
		//cout<<"Can't select data: "<<sqlite3_errmsg(db)<<endl;
		sqlite3_close(db);
	}
	//Отображаем на экране

	int     rec_count = 0;
	 VirtualStringTree1 ->BeginUpdate();
	while (sqlite3_step(result) == SQLITE_ROW)
	{   PVirtualNode entryNode = VirtualStringTree1 -> AddChild(VirtualStringTree1 -> RootNode);
		MyHistory *nodeData = (MyHistory*)VirtualStringTree1 -> GetNodeData(entryNode);
		nodeData -> id = sqlite3_column_int64(result, 0) ;
		nodeData -> name =(char*)sqlite3_column_text(result, 1);
		 //nodeData -> title = (UnicodeString)(char *)sqlite3_column_text(result, 2);

	   //	Edit1 ->Text = ((char*)(sqlite3_column_text(result, 2)));
		rec_count++;
    }
	  sqlite3_finalize(result);

	sqlite3_close(db);
	VirtualStringTree1 ->EndUpdate();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
VirtualStringTree1 -> NodeDataSize = sizeof(MyHistory);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::VirtualStringTree1GetText(TBaseVirtualTree *Sender, PVirtualNode Node,
          TColumnIndex Column, TVSTTextType TextType, UnicodeString &CellText)

{
if (!Node) return;
	 MyHistory *nodeData = (MyHistory *)Sender -> GetNodeData(Node);
	switch (Column)
		{
		   case 0: CellText = nodeData -> id;break;
		   case 1: CellText= nodeData ->name; break;
		  // case 2: CellText = nodeData -> title; break;
		}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{    PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
//unsigned int selectedNodeIndex = selectedNode->Index;
MyHistory *nodeData = (MyHistory*)VirtualStringTree1->GetNodeData(selectedNode);
VirtualStringTree1->DeleteNode(selectedNode);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1NodeClick(TBaseVirtualTree *Sender, const THitInfo &HitInfo)

{
PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;
if(!selectedNode)
{
	//...
	//return;
}
}
//---------------------------------------------------------------------------

