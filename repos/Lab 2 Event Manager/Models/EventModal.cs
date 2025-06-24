using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;

using System.ComponentModel.DataAnnotations;

namespace EventManager.Models
{
    public class EventModel
    {
        public int Id { get; set; }

        [Required(ErrorMessage = "Внесете име на настан")]
        public string Ime { get; set; }

        [Required(ErrorMessage = "Внесете локација")]
        public string Lokacija { get; set; }
    }
}
