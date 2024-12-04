# Philosophers

<p>This projects simulates the clasic Dining Philosophers problem.<\p>
- The philosophers can be in tree states: eating, thinking or sleeping.
- There's the same number of philosophers than forks.
- The philosopher needs two forks to eat.

# Technical requirements
The programs accepts the following argments:
- Number of philosophers.
- Time to die.
- Time to eat.
- Time to sleep.
- (optinal argument) Number of times each philosopher should eat.

El proyecto simula el problema clásico de los filósofos cenando (Dining Philosophers Problem)
Los filósofos pueden estar en tres estados: comiendo, pensando o durmiendo
Hay tantos tenedores como filósofos
Un filósofo necesita dos tenedores para comer

Requisitos Técnicos Principales

Argumentos del Programa

Número de filósofos
Tiempo para morir (en milisegundos)
Tiempo para comer (en milisegundos)
Tiempo para dormir (en milisegundos)
(Opcional) Número de veces que cada filósofo debe comer


Restricciones Técnicas

Prohibido usar variables globales
Cada filósofo es un hilo (thread)
Usar mutex para proteger los tenedores
Evitar race conditions
Gestionar correctamente la memoria (sin memory leaks)

Los filosofos --> comen, duermen y piensan. NO pueden hacer 2 cosas a la vez.

NUM de tenedores = Num de filosofos

Necesitan 2 tenedores para comer. Comen, (dejan los tenedores),  duermen y piensan.
