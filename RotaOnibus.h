typedef struct RotaOnibus *Lista;

typedef struct descritor ListaCidade;

Lista *criarLista();

ListaCidade *criarLista2();

void cadastrarRota(Lista *list);

void cadastraPonto(Lista *list, int rotas);

int excluirRota(Lista *list);

void imprimeLista(Lista *list);

void liberarLista(Lista *list);

void liberarLista2(ListaCidade *cidade);
