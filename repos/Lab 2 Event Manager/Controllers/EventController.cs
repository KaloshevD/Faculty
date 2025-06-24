using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using EventManager.Models;

namespace EventManager.Controllers
{
    public class EventController : Controller
    {
        private static List<EventModel> Events = new List<EventModel>();

        public ActionResult Index()
        {
            return View(Events);
        }

        public ActionResult Details(int id)
        {
            var selectedEvent = Events.FirstOrDefault(e => e.Id == id);
            if (selectedEvent == null)
                return HttpNotFound();

            return View(selectedEvent);
        }

        public ActionResult Edit(int id)
        {
            var e = Events.FirstOrDefault(x => x.Id == id);
            if (e == null)
                return HttpNotFound();

            return View(e);
        }

        public ActionResult Delete(int id)
        {
            var e = Events.FirstOrDefault(x => x.Id == id);
            if (e != null)
            {
                Events.Remove(e);
            }

            return RedirectToAction("Index");
        }


        [HttpPost]
        public ActionResult Edit(EventModel eventModel)
        {
            if (ModelState.IsValid)
            {
                var e = Events.FirstOrDefault(x => x.Id == eventModel.Id);
                if (e != null)
                {
                    e.Ime = eventModel.Ime;
                    e.Lokacija = eventModel.Lokacija;
                }
                return RedirectToAction("Index");
            }

            return View(eventModel);
        }


        public ActionResult Create()
        {
            return View();
        }

        [HttpPost]
        public ActionResult Create(EventModel eventModel)
        {
            if (ModelState.IsValid)
            {
                int nextId = Events.Count == 0 ? 1 : Events.Max(e => e.Id) + 1;
                eventModel.Id = nextId;
                Events.Add(eventModel);
                return RedirectToAction("Details", new { id = eventModel.Id });
            }

            return View(eventModel);
        }

    }

}