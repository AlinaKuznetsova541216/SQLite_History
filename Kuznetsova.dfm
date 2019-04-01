object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 396
  ClientWidth = 968
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 8
    Top = 363
    Width = 169
    Height = 25
    Caption = #1055#1086#1082#1072#1079#1072#1090#1100' '#1080#1089#1090#1086#1088#1080#1102
    TabOrder = 0
    OnClick = Button1Click
  end
  object VirtualStringTree1: TVirtualStringTree
    Left = 16
    Top = 8
    Width = 857
    Height = 337
    Header.AutoSizeIndex = -1
    Header.MainColumn = 1
    Header.Options = [hoColumnResize, hoDrag, hoShowHint, hoShowSortGlyphs, hoVisible]
    TabOrder = 1
    TreeOptions.SelectionOptions = [toExtendedFocus, toAlwaysSelectNode]
    OnGetText = VirtualStringTree1GetText
    OnNodeClick = VirtualStringTree1NodeClick
    Columns = <
      item
        Position = 0
        Text = 'id'
        Width = 103
      end
      item
        Position = 1
        Text = 'name'
        Width = 618
      end>
  end
  object Button2: TButton
    Left = 240
    Top = 363
    Width = 233
    Height = 25
    Caption = #1059#1076#1072#1083#1080#1090#1100' '#1079#1072#1087#1080#1089#1100
    TabOrder = 2
    OnClick = Button2Click
  end
end
