/*
 * Initial main.c file generated by Glade. Edit as required.
 * Glade will not overwrite this file.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "interface.h"
#include "support.h"

int
main (int argc, char *argv[])
{
  GtkWidget *acceuil;
  GtkWidget *ajouter;
  GtkWidget *modifier;
  GtkWidget *liste_des_capteurs;
  GtkWidget *Home;

#ifdef ENABLE_NLS
  bindtextdomain (GETTEXT_PACKAGE, PACKAGE_LOCALE_DIR);
  bind_textdomain_codeset (GETTEXT_PACKAGE, "UTF-8");
  textdomain (GETTEXT_PACKAGE);
#endif

  gtk_set_locale ();
  gtk_init (&argc, &argv);

  add_pixmap_directory ( "../pixmaps");

  /*
   * The following code was added by Glade to create one of each component
   * (except popup menus), just so that you see something after building
   * the project. Delete any components that you don't want shown initially.
   */
  /*acceuil = create_acceuil ();
  gtk_widget_show (acceuil);
  ajouter = create_ajouter ();
  gtk_widget_show (ajouter);
  modifier = create_modifier ();
  gtk_widget_show (modifier);
  liste_des_capteurs = create_liste_des_capteurs ();
  gtk_widget_show (liste_des_capteurs);*/
  Home = create_Home();
  gtk_widget_show(Home);

  gtk_main ();
  return 0;
}

