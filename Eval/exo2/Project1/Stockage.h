typedef struct tStock {

    int n_id; 
    char* str_nom[20];
    char* str_prenom[15];
    int n_age;
    char* str_tel[11];

}tStock;

extern void initStock(tStock* ptr_stock);
extern void saveStock(tStock* myStock);
extern void loadStock(tStock* myStock);