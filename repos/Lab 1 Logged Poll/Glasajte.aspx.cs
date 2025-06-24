using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using Microsoft.AspNet.FriendlyUrls;

namespace LaboratoriskaVezba1
{
	public partial class Glasajte : System.Web.UI.Page
	{
		protected void Update_Selection(ListBox listbox1, ListBox listbox2)
		{
            if (listbox1 != null)
            {
                string NameOfProfessor = listbox1.SelectedItem.Value.ToString();
                ProfessorNameLabel.Text = NameOfProfessor;
                listbox2.SelectedIndex = listbox1.SelectedIndex;

                if (listbox2 != null)
                {
                    ProfessorNameLabel.Text = NameOfProfessor;
                    listbox1.SelectedIndex = listbox2.SelectedIndex;
                }
            }
		}

        protected void Predmeti_SelectedIndexChanged(object sender, EventArgs e)
        {
            Update_Selection(Predmeti, Krediti);
            ////if an item from Predmeti is selected first
            //if (Predmeti.SelectedItem != null) {

            //    string name = Predmeti.SelectedItem.Value.ToString();
            //    Console.WriteLine(name);
            //    ProfessorNameLabel.Text = name;
            //    Krediti.SelectedIndex = Predmeti.SelectedIndex;
            //    if (Krediti.SelectedItem != null)
            //    {
            //        ProfessorNameLabel.Text = name;
            //        Krediti.SelectedIndex = Predmeti.SelectedIndex;
            //    }
            //}

     
        }
        protected void Krediti_SelectedIndexChanged(object sender, EventArgs e)
        {

            Update_Selection(Krediti, Predmeti);
            //if an item from Krediti is selected first
            //if (Krediti.SelectedItem != null)
            //{
            //    string name = Krediti.SelectedItem.Value.ToString();
            //    Console.WriteLine(name);
            //    ProfessorNameLabel.Text = name;
            //    Predmeti.SelectedIndex = Krediti.SelectedIndex;
            //    if (Predmeti.SelectedItem != null)
            //    {
            //        ProfessorNameLabel.Text = name;
            //        Predmeti.SelectedIndex = Krediti.SelectedIndex;
            //    }
            //}
        }

        protected void Redirect_UspesnoGlasanje(object sender, EventArgs e)
        {
            Response.Redirect("UspeshnoGlasanje.aspx");
        }
    }
}