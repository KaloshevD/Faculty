<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Glasajte.aspx.cs" Inherits="LaboratoriskaVezba1.Glasajte" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body style="height: 272px">
    <form id="form1" runat="server">
        <asp:Image ID="Image1" runat="server" ImageUrl="~/finki_52_1_2_1_62_0.png" Width="235px" style="margin-left: 34px" Height="125px" />
        <div style="margin-left: 40px; height: 137px;">
            <section><asp:Label ID="ProfessorNameLabel" runat="server" Text=""></asp:Label></section>
            <asp:ListBox ID="Predmeti" runat="server" OnSelectedIndexChanged="Predmeti_SelectedIndexChanged" Height="69px" style="margin-top: 43px" AutoPostBack="True">
                <asp:ListItem Value="Проф д-р Гоце Арменски">Интернет Технологии</asp:ListItem>
                <asp:ListItem Value="Проф д-р Бобан Стефановски">Интернет</asp:ListItem>
                <asp:ListItem Value="Проф д-р Вангјел Алексовски">Дигитална Електроника</asp:ListItem>
            </asp:ListBox>
            <asp:ListBox ID="Krediti" runat="server" AutoPostBack="True" OnSelectedIndexChanged="Krediti_SelectedIndexChanged">
                <asp:ListItem Value="Проф д-р Гоце Арменски">6</asp:ListItem>
                <asp:ListItem Value="Проф д-р Бобан Стефановски">5.5</asp:ListItem>
                <asp:ListItem Value="Проф д-р Вангјел Алексовски">4</asp:ListItem>
            </asp:ListBox>
        </div>
        <asp:Button ID="Button1" runat="server" Style="margin-left: 100px" Text="Гласајте" OnClick="Redirect_UspesnoGlasanje" />
    </form>
</body>
</html>
