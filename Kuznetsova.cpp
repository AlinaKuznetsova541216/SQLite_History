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
    UnicodeString author;
    UnicodeString dialog_partner;
	UnicodeString body_xml;
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

 using namespace std;
	const char *db_name="main.db";
	VirtualStringTree1 -> Clear();
    sqlite3_stmt *stmt;
    sqlite3* db;
	char* sql ="select * from messages;";
	int r = sqlite3_open(db_name ,&db);
	if (r!=SQLITE_OK) {
	Edit1->Text = String("������!")+sqlite3_errmsg(db);
	}
	else {
	Edit1->Text = "�� ������� ���������";
	}
	sqlite3_prepare_v2( db,sql, -1, &stmt, NULL);

    while (sqlite3_step(stmt) == SQLITE_ROW)
    {
		PVirtualNode entryNode = VirtualStringTree1 -> AddChild(VirtualStringTree1 -> RootNode);
		MyHistory *nodeData = (MyHistory*)VirtualStringTree1 -> GetNodeData(entryNode);
		nodeData -> id = sqlite3_column_int(stmt, 0) ;
		nodeData -> author   = (char*)sqlite3_column_text(stmt,4);
		nodeData -> dialog_partner = (char*)sqlite3_column_text( stmt, 8);
		nodeData -> body_xml = (char*)sqlite3_column_text(stmt, 18);
    }
    sqlite3_finalize(stmt);
    sqlite3_close(db);

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
           case 1: CellText =  nodeData -> author; break;
           case 2: CellText = nodeData -> dialog_partner; break;
		   case 3: CellText = nodeData -> body_xml; break;
		}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{     PVirtualNode selectedNode = VirtualStringTree1 -> FocusedNode;
	int selectedNodeIndex = selectedNode -> Index;

	 //int id =  VirtualStringTree1.TVTHeader.Columns[0];
	MyHistory *Data = (MyHistory*)VirtualStringTree1->GetNodeData(selectedNode);
	UnicodeString id = Data->id;
	sqlite3_stmt *stmt;
	const char *db_name="main.db";
	sqlite3* db;
	int r = sqlite3_open(db_name ,&db);
   String sql = String("DELETE from messages where id="+id);
   wchar_t *sql1 = sql.c_str();
   //MyHistory *nodeData = (MyHistory*)VirtualStringTree1 -> GetNodeData();
	//wchar_t* sql =("DELETE from messages where id="+id);
	sqlite3_prepare16_v2( db,sql1, -1, &stmt, NULL);
	sqlite3_step(stmt);
	if (true) {
		Edit1->Text="������ ������� �� ��";
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
	VirtualStringTree1 -> DeleteNode(selectedNode);
   //	Edit1->Text=sql1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::VirtualStringTree1NodeClick(TBaseVirtualTree *Sender, const THitInfo &HitInfo)

{
PVirtualNode selectedNode = VirtualStringTree1->FocusedNode;

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button3Click(TObject *Sender)
{
	// 	MyHistory *Data = (MyHistory*)VirtualStringTree1->GetNodeData(selectedNode);
	sqlite3_stmt *stmt;
	const char *db_name="main.db";
	sqlite3* db;
	int r = sqlite3_open(db_name ,&db);
   char *sql = "DELETE from messages";
   //wchar_t *sql1 = sql.c_str();
   //MyHistory *nodeData = (MyHistory*)VirtualStringTree1 -> GetNodeData();
	//wchar_t* sql =("DELETE from messages where id="+id);
	sqlite3_prepare_v2( db,sql, -1, &stmt, NULL);
	sqlite3_step(stmt);
	if (true) {
		Edit1->Text="���� ������ �������. ������ �����������";
	}
	sqlite3_finalize(stmt);
	sqlite3_close(db);
    VirtualStringTree1->Clear();
}
//---------------------------------------------------------------------------

