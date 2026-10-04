using System.Collections.Generic;
using System.Data.Entity;

public class ApplicationDbContext : DbContext
{
    public DbSet<Hospital> Hospitals { get; set; }
    public DbSet<Doctor> Doctors { get; set; }
    public DbSet<Patient> Patients { get; set; }

    public ApplicationDbContext() : base("DefaultConnection") { }

    protected override void OnModelCreating(DbModelBuilder modelBuilder)
    {
        base.OnModelCreating(modelBuilder);

        modelBuilder.Entity<Doctor>()
            .HasRequired(d => d.Hospital)
            .WithMany(h => h.Doctors)
            .HasForeignKey(d => d.HospitalId);

        modelBuilder.Entity<Doctor>()
            .HasMany(d => d.Patients)
            .WithMany(p => p.Doctors)
            .Map(m =>
            {
                m.ToTable("DoctorPatients");
                m.MapLeftKey("DoctorId");
                m.MapRightKey("PatientId");
            });
    }
}
