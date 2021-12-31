Simulação da energia depositada por partículas alpha ao longo da trajectória.

Neste exemplo uma partícula alpha é emitida com uma energia de 5.5 MeV dentro 
de um volume de ar. Sempre que ocorre uma interacção dentro deste volume
obtemos a energia depositada no passo e escrevemo-la no ecrã. Neste exemplo
limitamos o comprimento máximo de cada passo a 0.1 mm de forma a obtermos
a forma detalhada do pico de Bragg.

Intruções de compilação:
- make clean
- make

Como correr a simulação:
- a macro run1.mac pode ser editada de forma a alterar o número de partículas
alpha simuladas
- BraggPeak run1.mac
- abrir o ROOT e correr o script bragg_peak.C (.x bragg_peak.C)
- o nome do ficheiro de output pode ser alterado na classe SteppingAction (este mesmo nome tem que
  ser usado no script de ROOT)

