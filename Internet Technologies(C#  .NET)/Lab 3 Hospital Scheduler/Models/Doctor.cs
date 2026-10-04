using System.Collections.Generic;

public class Doctor
{
    public int Id { get; set; }
    public string FullName { get; set; }

    public int HospitalId { get; set; }
    public virtual Hospital Hospital { get; set; }

    public virtual ICollection<Patient> Patients { get; set; }
}
