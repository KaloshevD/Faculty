using System.Collections.Generic;
using System.ComponentModel.DataAnnotations;

public class Patient
{
    public int Id { get; set; }

    [Required(ErrorMessage = "Името е задолжително.")]
    public string FullName { get; set; }

    [Display(Name = "Код на пациентот")]
    [RegularExpression(@"^\d{5}$", ErrorMessage = "Кодот мора да содржи точно 5 цифри.")]
    public string PatientCode { get; set; }

    public string Gender { get; set; }

    public virtual ICollection<Doctor> Doctors { get; set; }
}
