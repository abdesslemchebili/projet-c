#include <gtk/gtk.h>
int i,j,k,l,m,n,h,d,q,r,c,g,p,v,w,x,y,z,a,c,d,e;

GtkWidget *acceuil;
GtkWidget *gestion_Capteur;
GtkWidget *catalogue;
GtkWidget *etages_contenant_des_pannes;
GtkWidget *capteurs_defectueux;
GtkWidget *liste_des_alarmes;

void on_button_ok_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_gosupp_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_gomodif_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_gorech_clicked               (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_goajout_clicked              (GtkWidget       *button,
                                        gpointer         user_data);


void on_Home_ajout_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_ajouter_clicked              (GtkWidget       *button,
                                        gpointer         user_data);

void on_radiobutton1_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void on_radiobutton2_ajout_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void on_button_homesupp_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_supp_clicked                 (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_homerech_clicked             (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_aff_clicked                  (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_homemodif_clicked            (GtkWidget       *button,
                                        gpointer         user_data);

void on_button_modif_clicked                (GtkWidget       *button,
                                        gpointer         user_data);

void on_checkbutton_n_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_t_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_s_toggled               (GtkToggleButton *togglebutton,
                                      	     gpointer         user_data);

void on_checkbutton_r_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_u_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_checkbutton_p_toggled               (GtkToggleButton *togglebutton,
                                             gpointer         user_data);

void on_radiobutton_modifF_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void on_radiobutton_modifH_toggled          (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_affich_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button_ajout_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_sup_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_app_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_suppx_clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_treeview11_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_affiche_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_ret_aff_clicked              (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ret_ajout_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ret_mod_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ret_sup_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_button_appajout_clicked             (GtkWidget      *objet,
                                        gpointer         user_data);

void
on_recherche_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);
void
on_ajout_clicked                       (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button1_ajout_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajou_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_supp_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_rech_ch_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_modi_ch_clicked                     (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview5_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_actua_ch_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);

void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_affi_ch_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_supp_tree_ch_clicked                (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton14_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton15_groupe_toggled        (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button5_ok__clicked                 (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button6_rec_ouvrier_clicked         (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button7_ajouter_clicked             (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_buttonINST_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_buttonFB_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview6_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button56_clicked                    (GtkWidget       *objet_graphique,
                                        gpointer         user_data);



void
on_button57_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_modif1_clicked               (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_radiobutton12_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton11_poste_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1111_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2222_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button3_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button4_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_mod_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_check_id_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_af_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button_aj_clicked                   (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview_row_activated              (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);


void
on_button_ajm_clicked                  (GtkWidget       *objet,
                                        gpointer         user_data);


void
on_afficher_clicked                    (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1x_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_AcceuiCatalogue_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_catalogue_Acceuil_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button22222_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_AjouterCapteur_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_SupprimerCapteur_clicked            (GtkButton       *button,
                                        gpointer         user_data);

void
on_ModifierCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button33333_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_chercherCapteur_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton2x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton3x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton1x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3x_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_pannes_clicked               (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmes_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteurs_defectueux_clicked  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_capteurDef_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_etagePanne_acceuil_clicked   (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_alarmes_acceuil_clicked      (GtkButton       *button,
                                        gpointer         user_data);
void
on_button2223_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2224_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2225_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2226_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2227_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

void
on_button2228_clicked                  (GtkButton       *button,
                                        gpointer         user_data);

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
on_button_create_acc_clicked           (GtkButton       *button,
                                        gpointer         user_data);

void
on_button_ajoutcc_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_radiobutton_cch_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton_ccf_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton_cc_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton4_cc_toggled             (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton5_ccf_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button_home_cc_clicked              (GtkButton       *button,
                                        gpointer         user_data);
