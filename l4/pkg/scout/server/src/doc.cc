/*
 * \brief  Browser content
 * \date   2008-08-14
 * \author Generated by GOSH
 */

/*
 * Copyright (C) 2008-2009
 * Genode Labs, Feske & Helmuth Systementwicklung GbR
 *
 * This file is part of the Genode OS framework, which is distributed
 * under the terms of the GNU General Public License version 2.
 */

#include <l4/scout-gfx/document>
#include <l4/scout-gfx/png_image>
#include <l4/scout-gfx/doc/link>
#include <l4/scout-gfx/doc/navbar>
#include <l4/scout-gfx/factory>
#include <l4/scout-gfx/doc/verbatim>
#include <l4/scout-gfx/doc/block>
#include <l4/scout-gfx/doc/item>
#include <l4/scout/styles>
#include <l4/scout-gfx/loadbar>

using namespace Scout_gfx;

Document *create_document(Factory *f)
{
	Document *doc = new Document();
	doc->title = "Walking through the Genode demo scenario";

	/**
	 * Table of contents
	 */

	Chapter *toc = new Chapter();
	Center *tc = new Center();
	tc->append(new Spacer(1, 20));

	/* anchor for section "Bootstrapping the system" */
	Anchor *anchor0 = new Anchor();

	Block *b0 = new Block();
	b0->append_text<Link_token>("Bootstrapping the system", &link_style, anchor0);
	tc->append(b0);

	/* anchor for section "The launchpad application starter" */
	Anchor *anchor1 = new Anchor();

	b0 = new Block();
	b0->append_text<Link_token>("The launchpad application starter", &link_style, anchor1);
	tc->append(b0);

	/* anchor for section "Recursive system structure" */
	Anchor *anchor2 = new Anchor();

	b0 = new Block();
	b0->append_text<Link_token>("Recursive system structure", &link_style, anchor2);
	tc->append(b0);

	/* anchor for section "The flexibility of nested policies" */
	Anchor *anchor3 = new Anchor();

	b0 = new Block();
	b0->append_text<Link_token>("The flexibility of nested policies", &link_style, anchor3);
	tc->append(b0);

	/* anchor for section "Where to go from here?" */
	Anchor *anchor4 = new Anchor();

	b0 = new Block();
	b0->append_text<Link_token>("Where to go from here?", &link_style, anchor4);
	tc->append(b0);
	toc->append(tc);
	toc->append(new Spacer(1, 20));
	doc->toc = toc;
	doc->append(new Spacer(1, 10));
	Block *title = new Block(Block::CENTER);
	title->append_plaintext("Walking through the Genode demo scenario", &chapter_style);
	//title->layout()->set_alignment(Mag_gfx::Align_h_center);
	doc->append(title);

	extern char _binary_genode_logo_png_start[];
	Png_image *png = new Png_image(_binary_genode_logo_png_start);
	doc->append(new Spacer(1, 10));
	doc->append(new Center(png));
	doc->append(new Spacer(1, 10));
	class Loadbar_l : public Loadbar_listener
  {
  public:
    void loadbar_changed(Loadbar *l, int mx)
    {
      int value = l->value_by_xpos(mx);
      l->value(value);
      l->refresh();
    }
  };
    //_launcher.quota(1024 * (unsigned long)value); };
	Loadbar *lb = new Loadbar(f, new Loadbar_l(), &label_font);
	lb->max_value(100);
	doc->append(lb);

	b0 = new Block();
	b0->append_plaintext("This guide provides a step-by-step guide through the demo scenario provided", &plain_style);
	b0->append_plaintext("with Genode. This scenario highlights the following features:", &plain_style);
	doc->append(b0);

	Item *i0 = new Item(&plain_style, " o", 20);

	Block *b1 = new Block();
	b1->append_plaintext("The creation of destruction of single processes as well as", &plain_style);
	b1->append_plaintext("arbitrarily complex sub systems", &plain_style);
	i0->append(b1);
	doc->append(i0);

	i0 = new Item(&plain_style, " o", 20);

	b1 = new Block();
	b1->append_plaintext("The trusted-path facility of the Nitpicker secure GUI", &plain_style);
	i0->append(b1);
	doc->append(i0);

	i0 = new Item(&plain_style, " o", 20);

	b1 = new Block();
	b1->append_plaintext("The assignment of resource quotas to sub systems", &plain_style);
	i0->append(b1);
	doc->append(i0);

	i0 = new Item(&plain_style, " o", 20);

	b1 = new Block();
	b1->append_plaintext("The multiple instantiation of services", &plain_style);
	i0->append(b1);
	doc->append(i0);

	i0 = new Item(&plain_style, " o", 20);

	b1 = new Block();
	b1->append_plaintext("The usage of run-time adaptable policy for routing", &plain_style);
	b1->append_plaintext("client requests to different services", &plain_style);
	i0->append(b1);
	doc->append(i0);

	/**
	 * Chapter "Bootstrapping the system"
	 */

	Chapter *chapter = new Chapter();
	chapter->append(anchor0);
	chapter->append(new Spacer(1, 20));

	b0 = new Block();
	b0->append_plaintext("Bootstrapping the system", &chapter_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("The Genode system is structured as a tree of processes with the core process", &plain_style);
	b0->append_plaintext("as the root of the tree. Core provides the most fundamental services that are", &plain_style);
	b0->append_plaintext("needed to start processes and manage physical resources such as the physical", &plain_style);
	b0->append_plaintext("memory and I/O devices.", &plain_style);
	b0->append_plaintext("Core provides these services as raw mechanisms and it is completely", &plain_style);
	b0->append_plaintext("free from policy. That means there exist no means of boot-time", &plain_style);
	b0->append_plaintext("configuration. You can think of core as the user-level portion of the", &plain_style);
	b0->append_plaintext("underlying kernel.", &plain_style);
	b0->append_plaintext("The only built-in policy of core is starting the init process and", &plain_style);
	b0->append_plaintext("transferring all physical resources such as all the available memory to init.", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("In contrast to core, init is driven by policy.", &plain_style);
	b0->append_plaintext("This policy defines the static bootstrapping of further processes and it is", &plain_style);
	b0->append_plaintext("expressed via XML syntax in init's", &plain_style);
	b0->append_plaintext("config", &mono_style);
	b0->append_plaintext("file.", &plain_style);
	b0->append_plaintext("init obtains this file from core's ROM service as a ROM module.  For the", &plain_style);
	b0->append_plaintext("demo scenario executed on Linux, the config file looks as follows:", &plain_style);
	chapter->append(b0);

	Verbatim *v0 = new Verbatim(verbatim_bgcol);
	v0->append_textline("<config>", &mono_style);
	v0->append_textline("  <start>", &mono_style);
	v0->append_textline("    <filename>fb_sdl</filename>", &mono_style);
	v0->append_textline("    <ram_quota>2M</ram_quota>", &mono_style);
	v0->append_textline("  </start>", &mono_style);
	v0->append_textline("  <start>", &mono_style);
	v0->append_textline("    <filename>timer</filename>", &mono_style);
	v0->append_textline("    <ram_quota>0x10000</ram_quota>", &mono_style);
	v0->append_textline("  </start>", &mono_style);
	v0->append_textline("  <start>", &mono_style);
	v0->append_textline("    <filename>nitpicker</filename>", &mono_style);
	v0->append_textline("    <ram_quota>1M</ram_quota>", &mono_style);
	v0->append_textline("  </start>", &mono_style);
	v0->append_textline("  <start>", &mono_style);
	v0->append_textline("    <filename>scout</filename>", &mono_style);
	v0->append_textline("    <ram_quota>2G</ram_quota>", &mono_style);
	v0->append_textline("  </start>", &mono_style);
	v0->append_textline("</config>", &mono_style);
	chapter->append(v0);

	b0 = new Block();
	b0->append_plaintext("Init's configuration is a list of processes to be started as children of", &plain_style);
	b0->append_plaintext("init, whereas the order of the", &plain_style);
	b0->append_plaintext("start", &mono_style);
	b0->append_plaintext("entries defines the starting", &plain_style);
	b0->append_plaintext("order of the processes.", &plain_style);
	b0->append_plaintext("Each", &plain_style);
	b0->append_plaintext("start", &mono_style);
	b0->append_plaintext("entry can further describe policy to be applied to the process.", &plain_style);
	b0->append_plaintext("For the demo scenario, we have assigned a different amount of memory via", &plain_style);
	b0->append_plaintext("the", &plain_style);
	b0->append_plaintext("ram_quota", &mono_style);
	b0->append_plaintext("definition to each process.", &plain_style);
	b0->append_plaintext("If the specified value exceeds the available memory (see the scout", &plain_style);
	b0->append_plaintext("entry), init assigns all of the remaining available memory to the process.", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("The processes started by this configuration are the following:", &plain_style);
	chapter->append(b0);

	Block *descitem = new Block(32);
	descitem->append_plaintext("fb_sdl", &bold_style);
	descitem->append_plaintext("is a process that provides services for accessing the", &plain_style);
	descitem->append_plaintext("frame buffer and for requesting user input. The interfaces for these", &plain_style);
	descitem->append_plaintext("services are platform independent but", &plain_style);
	descitem->append_plaintext("fb_sdl", &mono_style);
	descitem->append_plaintext("is a Linux-specific", &plain_style);
	descitem->append_plaintext("implementation of these services that relies on", &plain_style);
	descitem->append_plaintext("libSDL.", &mono_style);
	descitem->append_plaintext("On bare", &plain_style);
	descitem->append_plaintext("hardware, the config file contains entries for the dedicated driver", &plain_style);
	descitem->append_plaintext("components", &plain_style);
	descitem->append_plaintext("ps2_drv", &mono_style);
	descitem->append_plaintext("and", &plain_style);
	descitem->append_plaintext("vesa_drv", &mono_style);
	descitem->append_plaintext("instead of", &plain_style);
	descitem->append_plaintext("fb_sdl.", &mono_style);

	chapter->append(descitem);

	descitem = new Block(32);
	descitem->append_plaintext("timer", &bold_style);
	descitem->append_plaintext("is a process that enables other processes to wait for a", &plain_style);
	descitem->append_plaintext("specified amount of time.", &plain_style);

	chapter->append(descitem);

	descitem = new Block(32);
	descitem->append_plaintext("nitpicker", &bold_style);
	descitem->append_plaintext("is a low-complexity GUI server that allows multiple", &plain_style);
	descitem->append_plaintext("graphical applications to share the graphics device and user", &plain_style);
	descitem->append_plaintext("input in a secure fashion. More information about its concept are", &plain_style);
	descitem->append_plaintext("provided by the following paper:", &plain_style);

	descitem->append_plaintext("Norman Feske and Christian Helmuth:", &plain_style);
	descitem->append_plaintext("\"A Nitpicker's guide to a minimal-complexity secure GUI\",", &plain_style);

	descitem->append_plaintext("(In proceedings of the 21st Annual Computer Security Applications Conference", &italic_style);
	descitem->append_plaintext("(ACSAC 2005), Tucson, Arizona, USA, December 2005)", &italic_style);

	descitem->append_plaintext("http://genode.org/about/publications", &link_style);

	chapter->append(descitem);

	descitem = new Block(32);
	descitem->append_plaintext("scout", &bold_style);
	descitem->append_plaintext("is the graphical text-browser application you are looking at right now.", &plain_style);
	descitem->append_plaintext("It receives all remaining memory quota from init.", &plain_style);


	chapter->append(descitem);

	Navbar *navbar = new Navbar(f, &navbar_style);
	navbar->prev_link("Home", doc);
	navbar->next_link("The launchpad application starter", anchor1);
	chapter->append(navbar);

	/**
	 * Chapter "The launchpad application starter"
	 */

	chapter = new Chapter();
	chapter->append(anchor1);
	chapter->append(new Spacer(1, 20));

	b0 = new Block();
	b0->append_plaintext("The launchpad application starter", &chapter_style);
	chapter->append(b0);

	extern char _binary_launchpad_png_start[];
	png = new Png_image(_binary_launchpad_png_start);
	chapter->append(new Spacer(1, 10));
	chapter->append(new Center(png));
	chapter->append(new Spacer(1, 10));

	b0 = new Block();
	b0->append_plaintext("Figure", &plain_style);
	b0->append_plaintext("launchpad", &link_style);
	b0->append_plaintext("shows the main window of the launchpad", &plain_style);
	b0->append_plaintext("application. It consists of three areas.", &plain_style);
	b0->append_plaintext("The upper area contains status information about launchpad", &plain_style);
	b0->append_plaintext("itself. The available memory quota is presented by a", &plain_style);
	b0->append_plaintext("grey-colored bar.", &plain_style);
	b0->append_plaintext("The middle area of the window contains the list of available", &plain_style);
	b0->append_plaintext("applications that can be started by clicking on the", &plain_style);
	b0->append_plaintext("application's name.", &plain_style);
	b0->append_plaintext("Before starting an application, the user can define the", &plain_style);
	b0->append_plaintext("amount of memory quota to donate to the new application", &plain_style);
	b0->append_plaintext("by adjusting the red bar using the mouse.", &plain_style);
	/** XXX:
	Launcher *l0 = new Launcher("launchpad", 1, 28*1024*1024);
	b0->append_launchertext("Start the launchpad by clicking on this link...", &link_style, l0);
	chapter->append(b0);
*/
	b0 = new Block();
	b0->append_plaintext("For a first test, you may set the memory quota of the", &plain_style);
	b0->append_plaintext("program named scout to 10MB and then click its name.", &plain_style);
	b0->append_plaintext("Thereupon, another instance of the scout text browser will be started", &plain_style);
	b0->append_plaintext("and the lower area of launchpad becomes populated with status", &plain_style);
	b0->append_plaintext("information about launchpad's children. Currently,", &plain_style);
	b0->append_plaintext("launchpad has scout as its only child. For each child, its", &plain_style);
	b0->append_plaintext("name, its memory quota, and a kill button are presented.", &plain_style);
	b0->append_plaintext("After having started scout, you will further notice a", &plain_style);
	b0->append_plaintext("change of launchpad's own status information as the", &plain_style);
	b0->append_plaintext("memory quota spent for scout is not directly available to launchpad", &plain_style);
	b0->append_plaintext("anymore.", &plain_style);
	chapter->append(b0);

	extern char _binary_setup_png_start[];
	png = new Png_image(_binary_setup_png_start);
	chapter->append(new Spacer(1, 10));
	chapter->append(new Center(png));
	chapter->append(new Spacer(1, 10));

	b0 = new Block();
	b0->append_plaintext("In Figure", &plain_style);
	b0->append_plaintext("setup", &link_style);
	b0->append_plaintext(", you see an illustration of the", &plain_style);
	b0->append_plaintext("current setup. At the very bottom, there are the kernel,", &plain_style);
	b0->append_plaintext("core, and init. Init has started", &plain_style);
	b0->append_plaintext("framebuffer, timer, input, nitpicker, and launchpad as", &plain_style);
	b0->append_plaintext("it children (note: on Linux, input and framebuffer are", &plain_style);
	b0->append_plaintext("both contained in the", &plain_style);
	b0->append_plaintext("fb_sdl", &mono_style);
	b0->append_plaintext("process). Launchpad", &plain_style);
	b0->append_plaintext("has started the second instance of scout as its only child.", &plain_style);
	b0->append_plaintext("You can get a further idea about the relationship", &plain_style);
	b0->append_plaintext("between the applications visible on screen, by pressing", &plain_style);
	b0->append_plaintext("the", &plain_style);
	b0->append_plaintext("ScrLk", &mono_style);
	b0->append_plaintext("key, which gets especially handled by the", &plain_style);
	b0->append_plaintext("nitpicker GUI server. We call this key the X-ray key because", &plain_style);
	b0->append_plaintext("it makes the identity of each window on screen visible", &plain_style);
	b0->append_plaintext("to the user. Each screen region gets labeled by its", &plain_style);
	b0->append_plaintext("chain of parents and their grandparents respectively.", &plain_style);
	b0->append_plaintext("For example, the window of the second scout instance is labeled", &plain_style);
	b0->append_plaintext("with", &plain_style);
	b0->append_plaintext("\"scout -> launchpad -> scout\"", &italic_style);
	b0->append_plaintext(",", &plain_style);
	b0->append_plaintext("which tells us that this program was started by launchpad, which,", &plain_style);
	b0->append_plaintext("in turn, was started by the first instance of scout.", &plain_style);
	b0->append_plaintext("During the walk through the demo scenario, you may", &plain_style);
	b0->append_plaintext("press the X-ray key at any time to make the parent-child", &plain_style);
	b0->append_plaintext("relationships visible on screen.", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("By pressing the kill button (labeled with", &plain_style);
	b0->append_plaintext("x", &mono_style);
	b0->append_plaintext(") of the scout child", &plain_style);
	b0->append_plaintext("in launchpad's window, scout will disappear and launchpad regains", &plain_style);
	b0->append_plaintext("its original memory quota.", &plain_style);
	b0->append_plaintext("Although killing a process may sound like a simple thing", &plain_style);
	b0->append_plaintext("to do, it is worthwhile to mention that scout was using", &plain_style);
	b0->append_plaintext("a number of services, for example core's LOG service, the", &plain_style);
	b0->append_plaintext("nitpicker GUI service, and the timer service. While", &plain_style);
	b0->append_plaintext("using these services, scout made portions of its own memory", &plain_style);
	b0->append_plaintext("quota available to them.", &plain_style);
	b0->append_plaintext("When scout was killed by launchpad, all those relationships", &plain_style);
	b0->append_plaintext("were gracefully reverted such that there is no resource", &plain_style);
	b0->append_plaintext("leakage.", &plain_style);
	chapter->append(b0);

	navbar = new Navbar(f, &navbar_style);
	navbar->prev_link("Bootstrapping the system", anchor0);
	navbar->next_link("Recursive system structure", anchor2);
	chapter->append(navbar);

	/**
	 * Chapter "Recursive system structure"
	 */

	chapter = new Chapter();
	chapter->append(anchor2);
	chapter->append(new Spacer(1, 20));

	b0 = new Block();
	b0->append_plaintext("Recursive system structure", &chapter_style);
	chapter->append(b0);

	extern char _binary_x_ray_small_png_start[];
	png = new Png_image(_binary_x_ray_small_png_start);
	chapter->append(new Spacer(1, 10));
	chapter->append(new Center(png));
	chapter->append(new Spacer(1, 10));

	b0 = new Block();
	b0->append_plaintext("Thanks to the recursive structure of Genode, the mechanisms", &plain_style);
	b0->append_plaintext("that function for a single application are also applicable to", &plain_style);
	b0->append_plaintext("whole sub systems.", &plain_style);
	b0->append_plaintext("As a test, you may configure the launchpad application", &plain_style);
	b0->append_plaintext("entry within the launchpad window to 20MB and start", &plain_style);
	b0->append_plaintext("another instance of launchpad.", &plain_style);
	b0->append_plaintext("A new launchpad window will appear. Apart from the status", &plain_style);
	b0->append_plaintext("information at the upper part of its window, it looks", &plain_style);
	b0->append_plaintext("completely identical to the first instance.", &plain_style);
	b0->append_plaintext("You may notice that the displayed available quota of the", &plain_style);
	b0->append_plaintext("second launchpad instance is lower then the 20MB. The", &plain_style);
	b0->append_plaintext("difference corresponds to the application's static memory", &plain_style);
	b0->append_plaintext("usage including the BSS segment and the double-buffer", &plain_style);
	b0->append_plaintext("backing store.", &plain_style);
	b0->append_plaintext("With the new instance, you may start further applications,", &plain_style);
	b0->append_plaintext("for example by clicking on", &plain_style);
	b0->append_plaintext("testnit.", &mono_style);
	b0->append_plaintext("To distinguish the different instances of the applications", &plain_style);
	b0->append_plaintext("on screen, the X-ray key becomes handy again.", &plain_style);
	b0->append_plaintext("Figure", &plain_style);
	b0->append_plaintext("x-ray_small", &link_style);
	b0->append_plaintext("shows a screenshot of the described setup", &plain_style);
	b0->append_plaintext("in X-ray mode.", &plain_style);
	b0->append_plaintext("Now, after creating a whole hierarchy of applications,", &plain_style);
	b0->append_plaintext("you can try killing the whole tree at once by clicking", &plain_style);
	b0->append_plaintext("the kill button of the launchpad entry in the original", &plain_style);
	b0->append_plaintext("launchpad window.", &plain_style);
	b0->append_plaintext("You will notice that whole sub system gets properly", &plain_style);
	b0->append_plaintext("destructed and the original system state is regained.", &plain_style);
	chapter->append(b0);

	navbar = new Navbar(f, &navbar_style);
	navbar->prev_link("The launchpad application starter", anchor1);
	navbar->next_link("The flexibility of nested policies", anchor3);
	chapter->append(navbar);

	/**
	 * Chapter "The flexibility of nested policies"
	 */

	chapter = new Chapter();
	chapter->append(anchor3);
	chapter->append(new Spacer(1, 20));

	b0 = new Block();
	b0->append_plaintext("The flexibility of nested policies", &chapter_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("Beside providing the ability to construct and destruct", &plain_style);
	b0->append_plaintext("hierarchically structured sub systems, the recursive", &plain_style);
	b0->append_plaintext("system structure allows for an extremely flexible", &plain_style);
	b0->append_plaintext("definition and management of system policies that can", &plain_style);
	b0->append_plaintext("be implanted into each parent.", &plain_style);
	b0->append_plaintext("As an example, launchpad has a simple built-in policy of how", &plain_style);
	b0->append_plaintext("children are connected to services.", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("If a child requests", &plain_style);
	b0->append_plaintext("a service, launchpad looks if such a service is provided", &plain_style);
	b0->append_plaintext("by any of the other children and, if so, a connection", &plain_style);
	b0->append_plaintext("gets established. If the service is not offered by any child,", &plain_style);
	b0->append_plaintext("launchpad delegates the request to its parent.", &plain_style);
	b0->append_plaintext("For example, a request for the", &plain_style);
	b0->append_plaintext("LOG", &mono_style);
	b0->append_plaintext("service will always", &plain_style);
	b0->append_plaintext("end up at core, which implements the service by the", &plain_style);
	b0->append_plaintext("means of terminal (or kernel debug) output.", &plain_style);
	b0->append_plaintext("By starting a child that offers the same service interface,", &plain_style);
	b0->append_plaintext("however, we can shadow core's", &plain_style);
	b0->append_plaintext("LOG", &mono_style);
	b0->append_plaintext("service by an alternative", &plain_style);
	b0->append_plaintext("implementation.", &plain_style);
	b0->append_plaintext("You can try this out by first starting", &plain_style);
	b0->append_plaintext("testnit", &mono_style);
	b0->append_plaintext("and", &plain_style);
	b0->append_plaintext("observing its log output at the terminal window. When", &plain_style);
	b0->append_plaintext("started,", &plain_style);
	b0->append_plaintext("testnit", &mono_style);
	b0->append_plaintext("tells us some status information.", &plain_style);
	b0->append_plaintext("By further starting the program called", &plain_style);
	b0->append_plaintext("nitlog,", &mono_style);
	b0->append_plaintext("we create", &plain_style);
	b0->append_plaintext("a new", &plain_style);
	b0->append_plaintext("LOG", &mono_style);
	b0->append_plaintext("service as child of launchpad. On screen, this", &plain_style);
	b0->append_plaintext("application appears just as a black window that can be", &plain_style);
	b0->append_plaintext("dragged to any screen position with the mouse.", &plain_style);
	b0->append_plaintext("When now starting a new instance of", &plain_style);
	b0->append_plaintext("testnit", &mono_style);
	b0->append_plaintext(", launchpad", &plain_style);
	b0->append_plaintext("will resolve the request for the", &plain_style);
	b0->append_plaintext("LOG", &mono_style);
	b0->append_plaintext("service by establishing", &plain_style);
	b0->append_plaintext("a connection to", &plain_style);
	b0->append_plaintext("nitlog", &mono_style);
	b0->append_plaintext("instead of propagating the request", &plain_style);
	b0->append_plaintext("to its parent. Consequently, we can now observe the status", &plain_style);
	b0->append_plaintext("output of the second", &plain_style);
	b0->append_plaintext("testnit", &mono_style);
	b0->append_plaintext("instance inside the", &plain_style);
	b0->append_plaintext("nitlog", &mono_style);
	b0->append_plaintext("window.", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("The same methodology can be applied to arbitrarily complex", &plain_style);
	b0->append_plaintext("services. For example, you can create a new instance of", &plain_style);
	b0->append_plaintext("the framebuffer service by starting the", &plain_style);
	b0->append_plaintext("liquid_fb", &mono_style);
	b0->append_plaintext("application.", &plain_style);
	b0->append_plaintext("This application provides the framebuffer service and,", &plain_style);
	b0->append_plaintext("in turn, it uses the nitpicker GUI server to get displayed on", &plain_style);
	b0->append_plaintext("screen. Because any new requests for a framebuffer will now be", &plain_style);
	b0->append_plaintext("served by the", &plain_style);
	b0->append_plaintext("liquid_fb", &mono_style);
	b0->append_plaintext("application, we can start another", &plain_style);
	b0->append_plaintext("instance of nitpicker. This instance uses", &plain_style);
	b0->append_plaintext("liquid_fb", &mono_style);
	b0->append_plaintext("as its", &plain_style);
	b0->append_plaintext("graphics back end and, in turn, provides the GUI service.", &plain_style);
	b0->append_plaintext("Now, when starting another instance of scout, the new scout", &plain_style);
	b0->append_plaintext("window will appear within", &plain_style);
	b0->append_plaintext("liquid_fb", &mono_style);
	b0->append_plaintext("too (Figure", &plain_style);
	b0->append_plaintext("liquid_fb_small", &link_style);
	b0->append_plaintext(").", &plain_style);
	chapter->append(b0);

	extern char _binary_liquid_fb_small_png_start[];
	png = new Png_image(_binary_liquid_fb_small_png_start);
	chapter->append(new Spacer(1, 10));
	chapter->append(new Center(png));
	chapter->append(new Spacer(1, 10));

	b0 = new Block();
	b0->append_plaintext("The extremely simple example policy implemented in launchpad", &plain_style);
	b0->append_plaintext("in combination with the recursive system structure of Genode", &plain_style);
	b0->append_plaintext("already provides a wealth of flexibility without the need", &plain_style);
	b0->append_plaintext("to recompile or reconfigure any application.", &plain_style);
	b0->append_plaintext("The policy implemented and enforced by a parent may", &plain_style);
	b0->append_plaintext("also deny services for its children or impose other restrictions.", &plain_style);
	b0->append_plaintext("For example, the window labels presented in X-ray mode are", &plain_style);
	b0->append_plaintext("successively defined by all parents and grandparents that", &plain_style);
	b0->append_plaintext("mediate the request of an application to the GUI service.", &plain_style);
	b0->append_plaintext("The scout window as the parent of launchpad imposes its", &plain_style);
	b0->append_plaintext("policy of labeling the GUI session with the label", &plain_style);
	b0->append_plaintext("\"launchpad\"", &italic_style);
	b0->append_plaintext(".", &plain_style);
	b0->append_plaintext("Init as the parent of scout again overrides this label", &plain_style);
	b0->append_plaintext("by the name of its immediate child from which the GUI request", &plain_style);
	b0->append_plaintext("comes from. Hence the label becomes", &plain_style);
	b0->append_plaintext("\"scout -> launchpad\"", &italic_style);
	b0->append_plaintext(".", &plain_style);
	chapter->append(b0);

	navbar = new Navbar(f, &navbar_style);
	navbar->prev_link("Recursive system structure", anchor2);
	navbar->next_link("Where to go from here?", anchor4);
	chapter->append(navbar);

	/**
	 * Chapter "Where to go from here?"
	 */

	chapter = new Chapter();
	chapter->append(anchor4);
	chapter->append(new Spacer(1, 20));

	b0 = new Block();
	b0->append_plaintext("Where to go from here?", &chapter_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("Although this little demonstration scratches only the surface of", &plain_style);
	b0->append_plaintext("Genode, we hope that the power of its underlying design becomes", &plain_style);
	b0->append_plaintext("apparent. The most distinctive property of Genode, however, is its", &plain_style);
	b0->append_plaintext("extremely low complexity. The functionality of the complete demo", &plain_style);
	b0->append_plaintext("scenario is implemented in less than 20,000 lines of source code", &plain_style);
	b0->append_plaintext("(LOC), including the GUI and the demo applications. As a point of", &plain_style);
	b0->append_plaintext("reference, when relying on libpng for decompressing the images as seen", &plain_style);
	b0->append_plaintext("in the text browser, this number doubles. In fact, the complete base", &plain_style);
	b0->append_plaintext("OS framework accounts for less source-code complexity than the code", &plain_style);
	b0->append_plaintext("needed for decoding the PNG images. To these numbers, the complexity", &plain_style);
	b0->append_plaintext("of the used underlying kernel must be added, for example 10-20 KLOC", &plain_style);
	b0->append_plaintext("for an L4 microkernel (or far more than 500 KLOC when relying on the", &plain_style);
	b0->append_plaintext("Linux kernel). In combination with a microkernel, Genode enables the", &plain_style);
	b0->append_plaintext("implementation of security-sensitive applications with a trusted", &plain_style);
	b0->append_plaintext("computing base (TCB) of some thousands rather than millions of lines", &plain_style);
	b0->append_plaintext("of code. If using a hypervisor as kernel for Genode, this advantage", &plain_style);
	b0->append_plaintext("can further be combined with compatibility to existing applications", &plain_style);
	b0->append_plaintext("executed on virtual machines.", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("More details, architectural and technical documents, our road", &plain_style);
	b0->append_plaintext("map, and the complete source code are available at", &plain_style);
	b0->append_plaintext("http://genode.org", &link_style);
	b0->append_plaintext(".", &plain_style);
	chapter->append(b0);

	b0 = new Block();
	b0->append_plaintext("The development of the Genode OS Framework is conducted as", &plain_style);
	b0->append_plaintext("an open-source community project, coordinated by Genode Labs,", &plain_style);
	b0->append_plaintext("a company founded by the original authors of Genode.", &plain_style);
	b0->append_plaintext("If you are interested in supporting our project through", &plain_style);
	b0->append_plaintext("participation or funding, please consider joining our", &plain_style);
	b0->append_plaintext("community (", &plain_style);
	b0->append_plaintext("http://genode.org", &link_style);
	b0->append_plaintext(") or contact Genode Labs", &plain_style);
	b0->append_plaintext("(", &plain_style);
	b0->append_plaintext("http://www.genode-labs.com", &link_style);
	b0->append_plaintext(").", &plain_style);
	chapter->append(b0);

	v0 = new Verbatim(verbatim_bgcol);
	v0->append_textline(" info@genode-labs.com", &mono_style);
	chapter->append(v0);

	navbar = new Navbar(f, &navbar_style);
	navbar->prev_link("The flexibility of nested policies", anchor3);
	chapter->append(navbar);

	navbar = new Navbar(f, &navbar_style);
	navbar->next_link("Bootstrapping the system", anchor0);
	doc->append(navbar);

	return doc;
}