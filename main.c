#include <stdio.h>   // Para operações de entrada e saída (printf, scanf)
#include <stdlib.h>  // Para alocação de memória (malloc, free)

// Definição da estrutura do nó da lista
typedef struct Node {
    int data;          // O dado armazenado no nó (pode ser adaptado para outros tipos)
    struct Node *next; // Ponteiro para o próximo nó na lista
} Node;

// Ponteiro global para o início da lista. Inicialmente, a lista está vazia.
Node *head = NULL;

// --- FUNÇÕES DE OPERAÇÕES ELEMENTARES ---

/**
 * @brief Insere um novo nó no final da lista.
 * @param value O valor inteiro a ser inserido.
 */
void insert(int value) {
    // 1. Aloca memória para o novo nó
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Falha na alocação de memória para o novo nó.\n");
        return; // Sai da função em caso de erro de memória
    }

    // 2. Atribui o valor e define o ponteiro 'next' como NULL (pois será o último)
    newNode->data = value;
    newNode->next = NULL;

    // 3. Verifica se a lista está vazia
    if (head == NULL) {
        head = newNode; // Se vazia, o novo nó se torna a cabeça da lista
    } else {
        // 4. Se a lista não estiver vazia, percorre até o último nó
        Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        // 5. Adiciona o novo nó no final
        current->next = newNode;
    }
    printf("Valor %d inserido com sucesso na lista.\n", value);
}

/**
 * @brief Consulta se um valor existe na lista.
 * @param value O valor inteiro a ser consultado.
 */
void search(int value) {
    // 1. Verifica se a lista está vazia
    if (head == NULL) {
        printf("A lista está vazia. Não é possível consultar.\n");
        return;
    }

    // 2. Percorre a lista em busca do valor
    Node *current = head;
    int position = 0; // Para registrar a posição (início em 0)
    while (current != NULL) {
        if (current->data == value) {
            printf("Valor %d encontrado na posição %d da lista.\n", value, position);
            return; // Valor encontrado, sai da função
        }
        current = current->next;
        position++;
    }
    // 3. Se o loop terminar, o valor não foi encontrado
    printf("Valor %d não encontrado na lista.\n", value);
}

/**
 * @brief Altera a primeira ocorrência de um valor na lista por um novo valor.
 * @param oldValue O valor a ser substituído.
 * @param newValue O novo valor.
 */
void update(int oldValue, int newValue) {
    // 1. Verifica se a lista está vazia
    if (head == NULL) {
        printf("A lista está vazia. Não é possível alterar.\n");
        return;
    }

    // 2. Percorre a lista em busca do valor antigo
    Node *current = head;
    while (current != NULL) {
        if (current->data == oldValue) {
            current->data = newValue; // Valor antigo encontrado, atualiza para o novo
            printf("Valor %d alterado para %d com sucesso.\n", oldValue, newValue);
            return; // Alteração realizada, sai da função
        }
        current = current->next;
    }
    // 3. Se o loop terminar, o valor antigo não foi encontrado
    printf("Valor %d não encontrado na lista para alteração.\n", oldValue);
}

/**
 * @brief Remove a primeira ocorrência de um valor da lista.
 * @param value O valor a ser removido.
 */
void delete(int value) {
    // 1. Verifica se a lista está vazia
    if (head == NULL) {
        printf("A lista está vazia. Não é possível remover.\n");
        return;
    }

    Node *current = head;
    Node *prev = NULL; // Ponteiro para o nó anterior (necessário para religar a lista)

    // 2. Caso especial: o nó a ser removido é a cabeça da lista
    if (current != NULL && current->data == value) {
        head = current->next; // A nova cabeça é o próximo nó
        free(current);        // Libera a memória do nó original da cabeça
        printf("Valor %d removido com sucesso da lista.\n", value);
        return;
    }

    // 3. Percorre a lista para encontrar o nó a ser removido e seu antecessor
    while (current != NULL && current->data != value) {
        prev = current;        // Guarda o nó atual como 'anterior'
        current = current->next; // Avança para o próximo nó
    }

    // 4. Se 'current' é NULL, o valor não foi encontrado
    if (current == NULL) {
        printf("Valor %d não encontrado na lista para remoção.\n", value);
        return;
    }

    // 5. Valor encontrado: religa os ponteiros e libera a memória do nó
    prev->next = current->next; // O nó anterior aponta para o nó após o 'current'
    free(current);              // Libera a memória do nó removido
    printf("Valor %d removido com sucesso da lista.\n", value);
}

/**
 * @brief Exibe todos os elementos presentes na lista, da cabeça ao final.
 */
void display() {
    // 1. Verifica se a lista está vazia
    if (head == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    // 2. Percorre a lista e imprime cada elemento
    Node *current = head;
    printf("Elementos da lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n"); // Indica o final da lista
}

/**
 * @brief Função principal (main) do programa.
 * Apresenta um menu ao usuário para interagir com as operações da lista.
 */
int main() {
    int choice, value, oldValue, newValue;

    do {
        // Exibe o menu de opções
        printf("\n--- Gerenciamento de Lista Simplesmente Encadeada ---\n");
        printf("1. Inserir elemento (ao final)\n");
        printf("2. Consultar elemento\n");
        printf("3. Alterar elemento\n");
        printf("4. Remover elemento\n");
        printf("5. Listar todos os elementos\n");
        printf("0. Sair do programa\n");
        printf("-----------------------------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice); // Lê a opção do usuário

        switch (choice) {
            case 1:
                printf("Digite o valor inteiro a ser inserido: ");
                scanf("%d", &value);
                insert(value); // Chama a função de inserção
                break;
            case 2:
                printf("Digite o valor inteiro a ser consultado: ");
                scanf("%d", &value);
                search(value); // Chama a função de consulta
                break;
            case 3:
                printf("Digite o valor antigo a ser alterado: ");
                scanf("%d", &oldValue);
                printf("Digite o novo valor para substituir: ");
                scanf("%d", &newValue);
                update(oldValue, newValue); // Chama a função de alteração
                break;
            case 4:
                printf("Digite o valor inteiro a ser removido: ");
                scanf("%d", &value);
                delete(value); // Chama a função de remoção
                break;
            case 5:
                display(); // Chama a função de listagem
                break;
            case 0:
                printf("Saindo do programa. Liberando toda a memória alocada...\n");
                // Importante: Libera a memória de todos os nós antes de sair para evitar vazamentos
                Node *current = head;
                while (current != NULL) {
                    Node *temp = current;
                    current = current->next;
                    free(temp); // Libera o nó atual
                }
                head = NULL; // Garante que a cabeça da lista seja NULL após a liberação
                break;
            default:
                printf("Opção inválida. Por favor, digite um número entre 0 e 5.\n");
        }
    } while (choice != 0); // O loop continua até que o usuário escolha a opção 0

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
