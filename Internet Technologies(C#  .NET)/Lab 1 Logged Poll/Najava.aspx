<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="Najava.aspx.cs" Inherits="LaboratoriskaVezba1.Najava" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
        <div class="" style="display:flex; gap: 20px; flex-direction: column;">
            <seciton class="row, mx-0">
                <asp:Label ID="LabelName" runat="server" style="padding-right: 20px" Text="Име"></asp:Label>
                <asp:TextBox ID="Name" runat="server" BorderColor="Black" BorderWidth="1px" Height="16px" style="margin-left: 78px" Width="114px"></asp:TextBox>
            </seciton>
            <section class="row">
                <asp:Label ID="LabelSurname" runat="server" style="padding-right: 20px" Text="Лозинка"></asp:Label>
                <asp:TextBox ID="Surname" runat="server" BorderWidth="1px" style="margin-left: 48px" Width="118px"></asp:TextBox>
            </section>
            <section class="row">
                <asp:Label ID="EmailLabel" runat="server" style="padding-right: 20px" Text="e-адреса"></asp:Label>
                <asp:TextBox ID="Email" runat="server" BorderWidth="1px" style="margin-left: 48px"></asp:TextBox>
            </section>
            <asp:Button ID="Button1" OnClick="Check_Input" runat="server" Text="Најавете се" style="margin-left: 126px;" Width="90px" />
        </div>
    </form>
</body>
</html>
