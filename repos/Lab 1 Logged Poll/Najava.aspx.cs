using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;
using System.Linq;
using System.Text.RegularExpressions;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;

namespace LaboratoriskaVezba1
{
	public partial class Najava : System.Web.UI.Page
	{
        protected void Check_Input(object sender, EventArgs e)
		{
            bool ValidEmail()
            {
                string validationExpression = @"^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$";
                return Regex.IsMatch(Email.Text, validationExpression);
            }


            if (Name.Text != "" && Surname.Text != "" && ValidEmail())
			{
				Response.Redirect("Glasajte.aspx");
			}
		}
	}
}