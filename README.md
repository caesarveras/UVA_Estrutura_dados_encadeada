# UVA_Estrutura_dados_encadeada
Gerenciamento de Lista Simplesmente Encadeada em C
Descrição do Projeto
Este projeto consiste em um programa em linguagem C que implementa uma Lista Simplesmente Encadeada. O objetivo é demonstrar as operações elementares de manipulação de dados dentro dessa estrutura sequencial, simulando um cenário de programação para a empresa Renalf Mega Data.

A lista simplesmente encadeada é uma estrutura dinâmica onde cada elemento (nó) aponta para o próximo elemento na sequência, permitindo flexibilidade na inserção e remoção de dados sem a necessidade de realocar blocos de memória contíguos.

# Funcionalidades Implementadas
O programa oferece um menu interativo com as seguintes operações básicas sobre a lista:

´´´
Inclusão (insert): Adiciona um novo elemento ao final da lista.

Consulta (search): Verifica se um determinado valor existe na lista e, se sim, informa sua posição.

Alteração (update): Substitui a primeira ocorrência de um valor existente na lista por um novo valor.

Remoção (delete): Remove a primeira ocorrência de um valor especificado da lista.

Listagem (display): Exibe todos os elementos atualmente armazenados na lista, da cabeça ao final.
´´´

# Pré-requisitos
Para compilar e executar este programa, você precisará de um compilador C instalado em seu sistema. O GCC (GNU Compiler Collection) é altamente recomendado e está disponível para a maioria dos sistemas operacionais (Windows, macOS, Linux).

# Como Compilar e Executar
Siga os passos abaixo para colocar o programa em funcionamento:

Salve o Código: Copie o código-fonte C fornecido (o conteúdo do arquivo lista_encadeada.c) e salve-o em um arquivo com a extensão .c (ex: lista_encadeada.c).

Abra o Terminal/Prompt de Comando: Navegue até o diretório onde você salvou o arquivo lista_encadeada.c usando o terminal (Linux/macOS) ou o Prompt de Comando/PowerShell (Windows).

Compile o Código: Use o compilador C (por exemplo, gcc) para compilar o arquivo-fonte. No terminal, execute:

gcc lista_encadeada.c -o lista_encadeada

Este comando criará um arquivo executável chamado lista_encadeada (ou lista_encadeada.exe no Windows).

Execute o Programa: Após a compilação bem-sucedida, execute o programa:

´´´
./lista_encadeada
´´´

# Como Usar
Ao executar o programa, você verá um menu de opções no console:
´´´
--- Gerenciamento de Lista Simplesmente Encadeada ---
1. Inserir elemento (ao final)
2. Consultar elemento
3. Alterar elemento
4. Remover elemento
5. Listar todos os elementos
0. Sair do programa
-----------------------------------------------------
Escolha uma opção:
´´´
Digite o número correspondente à operação desejada e pressione Enter. O programa solicitará as informações necessárias (como o valor a inserir, consultar, etc.) e exibirá os resultados. Para sair, digite 0.

# Considerações Importantes
Dados Temporários: É fundamental entender que este programa armazena os dados da lista apenas na memória RAM enquanto está em execução. Isso significa que, ao fechar o programa, todos os dados são perdidos. Não há persistência de dados em disco (como em arquivos ou bancos de dados).

Alocação e Liberação de Memória: O programa faz uso intensivo de malloc para alocar memória para novos nós e free para liberar essa memória quando os nós são removidos ou quando o programa é encerrado. Isso é crucial para evitar vazamentos de memória.

# Melhorias Futuras:

´´´
Persistência de Dados: Implementar a gravação e leitura da lista em um arquivo (texto ou binário) para que os dados não sejam perdidos ao encerrar o programa.

Inserção em Posição Específica: Adicionar funções para inserir um elemento no início da lista ou em uma posição arbitrária.

Contagem de Elementos: Uma função para retornar o número total de elementos na lista.

Lista Duplamente Encadeada: Evoluir a estrutura para uma lista duplamente encadeada, onde cada nó aponta para o próximo e para o anterior, facilitando certas operações (como a remoção, em alguns casos).

Tratamento de Erros Aprimorado: Adicionar validações mais robustas para a entrada do usuário e tratamento de possíveis erros.
´´´
