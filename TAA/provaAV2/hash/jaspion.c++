/*Em 1985 estréia na TV Japonesa a série Kyojiu Tokusou Jaspion (Investigador Especial de Monstros Jaspion). A série chega ao Brasil alguns anos depois com o título “O Fantástico Jaspion”, e com ela nasce a fantasia de polícia espacial em milhões de brasileirinhos. As crianças saíam da escola, corriam pelas ruas (sem olhar se vinha carro), ligavam a TV e mergulhavam na coragem, exemplo de pessoa, e incontestável sede por justiça do Fantástico Jaspion. O comércio de gibis e as brigas por figurinhas no recreio da escola estavam alcançando números históricos. Até então, tal sentimento só havia sido estimulado com tanta intensidade pelo Chaves e a sua turma! Diante dessa febre inter-galática, o inevitável aconteceu. Os produtores do Jaspion ganharam o Nobel da Paz! Isso mesmo! Os produtores ganharam um Nobel. As histórias do grandioso Jaspion estavam por todo canto. Agora as crianças tinham um belíssimo exemplo para seguir. A paz mundial estava garantida! Não precisávamos mais temer o monstrengo Satan Gos!

No Brasil havia uma criança que adorava as histórias do Jaspion! Antônio Melhorança Capote Valente Junior carinhosamente apelidado de ACM, um menino da zona sul de São Paulo que adorava cantar as músicas do grande herói. Ele era tão fanático que chegou a comprar um dicionário de Japonês-Português e iniciou um trabalho árduo de tradução. Entretanto, o trabalho ficou inacabado! Alguns trechos da canção ainda precisam ser traduzidos. Neste momento você deve estar se perguntando: qual é a minha tarefa neste fabuloso problema? Ok! Antes de falar da sua tarefa, convide seu companheiro de equipe para mergulhar com você no desfecho da história. Para isso, vamos falar mais um pouco sobre o nosso ACM. Ele se formou em Ciência da Computação e hoje trabalha no mesmo escritório que você. Pois é! Você trabalha como programador ao lado dessa figura! Como sabemos que você gosta muito dele, temos certeza que vai aceitar a seguinte tarefa: dado um dicionário Japonês-Português e uma letra de música, escreva um programa que imprima a letra traduzida.

Entrada
A entrada é composta por diversas instâncias. A primeira linha da entrada contém um inteiro T indicando o número de instâncias.

A primeira linha de cada instância contém dois inteiros M e N (1 ≤ M ≤ 1000000, 1 ≤ N ≤ 1000), que representam o número de palavras no dicionário e o número de linhas na letra da música, respectivamente.

Os próximos M pares de linhas contêm as traduções: a primeira linha de cada par contém a palavra em Japonês, e a segunda linha contém a tradução para o Português (que pode ter uma ou mais palavras). Todas as palavras usam apenas letras minúsculas. Cada palavra em Japonês aparece apenas uma vez em cada instância.

As próximas N linhas contêm a letra da música. Cada linha da letra da música é uma lista de palavras separadas por um espaço (todas as palavras consistem apenas de letras minúsculas). Algumas podem estar vazias, mas nenhuma linha possui espaços no início ou no final.

Nenhuma linha contém mais do que 80 letras.

Saída
Para cada instância imprima as N linhas traduzidas. As palavras que não estão no dicionário devem ser impressas como aparecem na entrada. Imprima uma linha em branco após tradução, inclusive após a última.

Nenhuma linha da saída contém mais do que 80 letras.

Exemplo de Entrada	
2
4 3
galaxy
cara tossiu
kagayaku
canalha do
atsuki
alto que
yuushi
util
o galaxy
o galaxy
o kagayaku atsuki yuushi
3 1
bashulhan
sobre a mesa
hu
esta
hasefer
o livro
hasefer hu bashulhan

Exemplo de Saída
o cara tossiu
o cara tossiu
o canalha do alto que util

o livro esta sobre a mesa
*/

#include <iostream>
#include <unordered_map>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    cin.ignore();

    for (int t = 0; t < T; ++t) {
        int M, N;
        cin >> M >> N;
        cin.ignore();

        unordered_map<string, string> dictionary;
        string japanese, portuguese;

        // Read the dictionary
        for (int i = 0; i < M; ++i) {
            getline(cin, japanese);
            getline(cin, portuguese);
            dictionary[japanese] = portuguese;
        }

        // Read and translate the lyrics
        vector<string> lyrics(N);
        for (int i = 0; i < N; ++i) {
            getline(cin, lyrics[i]);
            istringstream iss(lyrics[i]);
            string word;
            string translatedLine;

            while (iss >> word) {
                if (!translatedLine.empty()) {
                    translatedLine += " ";
                }
                if (dictionary.find(word) != dictionary.end()) {
                    translatedLine += dictionary[word];
                } else {
                    translatedLine += word;
                }
            }
            lyrics[i] = translatedLine;
        }

        // Print the translated lyrics
        for (const auto &line : lyrics) {
            cout << line << '\n';
        }
        cout << '\n';  // Print the blank line after each instance
    }

    return 0;
}
