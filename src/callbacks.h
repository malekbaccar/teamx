#include <gtk/gtk.h>


void
on_buttonLogin_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_ctree1_tree_select_row              (GtkCTree        *ctree,
                                        GtkCTreeNode    *node,
                                        gint             column,
                                        gpointer         user_data);

void
on_button8_ajoutUser_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button10_deleteUser_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_button13_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_confirmer_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button12_annuler_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_combobox1_role_changed              (GtkComboBox     *combobox,
                                        gpointer         user_data);

void
on_button14_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button7_actualiser_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_button9_modifierUser_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_button15_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button16_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_entry10_prenom_grab_focus           (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_entry11_nom_grab_focus              (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_entry12_pass_grab_focus             (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_combobox2_role_grab_focus           (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_checkbutton2_grab_focus             (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_button17_alarmes_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button17_retour_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button18_logout_clicked             (GtkButton       *button,
                                        gpointer         user_data);



// stock

void
on_modifier_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_st_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_st_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouterpr_st_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_anuulerajout_st_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulersupp_st_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirmersupp_st_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supprimer_st_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_annulerM_st_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier1_st_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_fr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_nr_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton22_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_st_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton11_st_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_retire_st_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_st_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_afficher_tache2_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_confirme_ut_st_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_ut_st_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_Date_expir___toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_Stock_epuis___toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_gestion_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_rupture1_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton222_nr_toggled           (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2222_nr_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);




// capteurs




void
on_button10_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button11_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button12_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);
/*
void
on_button16_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);*/



void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button5_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

/*
void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
*/
void
on_radiobutton4_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button7_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_button16_hany_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton5_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton6_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton7_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button16chercher_clicked            (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_def_aff_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_button_capteur_def_clicked          (GtkWidget     *objet,
                                        gpointer         user_data);

void
on_buttonhome_exit_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_buttonhome_acceuil_clicked          (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button15_retour_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button14c_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_button6c_clicked                     (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_radiobutton9n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton8n_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton14_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton19n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton16n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton15n_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_date_exx_toggled                    (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


// menu


void
on_Menu_hsm_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_Meilleur_hsm_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_afficher_hsm_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2_hsm_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_vegetarien_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_choix1_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_choix2_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_ajout_hsm_clicked                   (GtkButton       *button,
                                        gpointer         user_data);



void
on_supprimer_hsm_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_hsm_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_actualiser_user_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercher_hsm_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_hsm_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_statistique_plat_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_meilleur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifier_hsm_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ajouter_hsm_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifier_hsm_clicked         (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ajouter_hsm_clicked          (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1h_row_activated            (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_autres_hsm_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_dec_homes_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_stg_clicked                      (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_capptg_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_mmenug_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_etudg_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_adming_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_st_tohome_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_button3_quitterstock_clicked        (GtkButton       *button,
                                        gpointer         user_data);

void
on_rtt_mn_hom_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

// etudiants


void
on_treeview1_user_row_activated        (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_go_ajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_supprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_modifier_clicked                 (GtkButton       *button,
                                        gpointer         user_data);



void
on_rechercher_user_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_deconn_user_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview1_et_row_activated          (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_ajouter_et_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_modifier_et_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_ajouteret_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_retour_modifier_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_annuler_supp_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_conf_supp_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_auth_et_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_inns_ett_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_insc_et_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_anul_ins_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat_etttttt_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_calculer2222_clicked                (GtkButton       *button,
                                        gpointer         user_data);

void
on_Go_afficger_clicked                 (GtkButton       *button,
                                        gpointer         user_data);

void
on_go_tach22_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_home_ett_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton17_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton16_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1_et_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_actualiser_et_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_retttt_2_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_ret_mn_22_clicked                   (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2H_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3H_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);
