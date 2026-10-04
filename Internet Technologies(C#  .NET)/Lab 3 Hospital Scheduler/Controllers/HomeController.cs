using System.Linq;
using System.Web.Mvc;

namespace Lab_3.Controllers
{
    public class HomeController : Controller
    {
        public ActionResult Index()
        {
            ViewBag.Message = "Добредојдовте во системот за закажување прегледи!";
            return View();
        }
        private ApplicationDbContext db = new ApplicationDbContext();

        // GET: Hospital
        public ActionResult Index1()
        {
            var hospitals = db.Hospitals.ToList();
            return View(hospitals);
        }
    }
}
