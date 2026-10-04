using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

public class Hospital
{
    public int Id { get; set; }

    [Required]
    public string Name { get; set; }

    public string Address { get; set; }

    public string ImageUrl { get; set; }

    public virtual ICollection<Doctor> Doctors { get; set; }
}
