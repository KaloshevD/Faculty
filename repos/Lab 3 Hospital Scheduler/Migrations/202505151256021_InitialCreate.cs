namespace Lab_3.Migrations
{
    using System;
    using System.Data.Entity.Migrations;
    
    public partial class InitialCreate : DbMigration
    {
        public override void Up()
        {
            CreateTable(
                "dbo.Doctors",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        FullName = c.String(),
                        HospitalId = c.Int(nullable: false),
                    })
                .PrimaryKey(t => t.Id)
                .ForeignKey("dbo.Hospitals", t => t.HospitalId, cascadeDelete: true)
                .Index(t => t.HospitalId);
            
            CreateTable(
                "dbo.Hospitals",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        Name = c.String(nullable: false),
                        Address = c.String(),
                        ImageUrl = c.String(),
                    })
                .PrimaryKey(t => t.Id);
            
            CreateTable(
                "dbo.Patients",
                c => new
                    {
                        Id = c.Int(nullable: false, identity: true),
                        FullName = c.String(nullable: false),
                        PatientCode = c.String(),
                        Gender = c.String(),
                    })
                .PrimaryKey(t => t.Id);
            
            CreateTable(
                "dbo.DoctorPatients",
                c => new
                    {
                        DoctorId = c.Int(nullable: false),
                        PatientId = c.Int(nullable: false),
                    })
                .PrimaryKey(t => new { t.DoctorId, t.PatientId })
                .ForeignKey("dbo.Doctors", t => t.DoctorId, cascadeDelete: true)
                .ForeignKey("dbo.Patients", t => t.PatientId, cascadeDelete: true)
                .Index(t => t.DoctorId)
                .Index(t => t.PatientId);
            
        }
        
        public override void Down()
        {
            DropForeignKey("dbo.DoctorPatients", "PatientId", "dbo.Patients");
            DropForeignKey("dbo.DoctorPatients", "DoctorId", "dbo.Doctors");
            DropForeignKey("dbo.Doctors", "HospitalId", "dbo.Hospitals");
            DropIndex("dbo.DoctorPatients", new[] { "PatientId" });
            DropIndex("dbo.DoctorPatients", new[] { "DoctorId" });
            DropIndex("dbo.Doctors", new[] { "HospitalId" });
            DropTable("dbo.DoctorPatients");
            DropTable("dbo.Patients");
            DropTable("dbo.Hospitals");
            DropTable("dbo.Doctors");
        }
    }
}
