# Penalty_Kick-OpenGl 
# ---------------------------------------------------------------
# Estrutura Geral:
O código em C faz uso da biblioteca OpenGL para criar um jogo de cobrança de pênaltis em 3D. Ele apresenta um ambiente gráfico interativo onde o jogador pode interagir com a cena.

# Inicialização:
O código inicia configurando as variáveis iniciais, como posições da bola, contadores de gols e erros, e configurações de câmera.

# Funções de Desenho:
Existem funções para desenhar elementos gráficos, como o campo, bola, gol, letras e barras, usando primitivas como glutSolidCube e glutSolidSphere.

# Controle de Animação:
O código controla a animação da bola em direção ao gol, bem como a animação do cubo que se move na frente do gol.

# Controle de Teclado:
O jogador pode interagir com o jogo usando o teclado. Por exemplo, 'A' e 'D' são usados para mover a bola lateralmente, 'Espaço' inicia o chute, 'Q' e 'W' alteram o zoom da cena, 'R' reinicia o jogo e as setas permitem rotacionar a câmera.

# Exibição de Texto:
O código exibe informações na tela, como o número de gols, erros e chutes, usando a função DesenhaTexto.

# Loop Principal:
O loop principal do jogo é mantido pela função glutMainLoop(), que atualiza a cena e aguarda eventos de entrada.

# Comentários:
O código contém comentários informativos que explicam a função de várias partes do programa, o que é útil para a compreensão do código.

# Organização:
O código é organizado em funções que desempenham papéis específicos, o que facilita a manutenção e compreensão do código.
