# Лабораторная работа №2

В большинстве современных ПК используется следующая иерархия памяти:
| Тип | Скорость доступа | Размер |
| - | - | - |
| Регистры процессора | порядка 1 такта | несколько сотен или тысяч байт |
| Кэш процессора L1 | порядка несколько тактов | десятки килобайт |
| Кэш процессора L2 | от 2 до 10 раз медленнее L1 | от 0.5Mb |
| Кэш процессора L3 | около сотни тактов | от нескольких мегабайт до сотен |
| Кэш процессора L4 (Intel 5 поколения) | несколько сотен тактов | >100Mb |
| ОЗУ | от сотен до тысяч тактов | от нескольких гигабайт до нескольких терабайт |
| Дисковое хранилище | миллионы тактов | до нескольких сотен терабайт |
| Третичная память | до нескольких секунд или минут | практически неограничен |

### Результаты

```
Ниже представлен формат и пример отчета:
investigation
  travel_order Direction
 experiments
 -experiment:
   number 1
   input_data:
     buffer_size: 96 kb
   results:
     direction: 8.78878 ms
   number 2
   input_data:
     buffer_size: 192 kb
   results:
     direction: 8.11787 ms
   number 3
   input_data:
     buffer_size: 384 kb
   results:
     direction: 22.9629 ms
   number 4
   input_data:
     buffer_size: 768 kb
   results:
     direction: 44.0733 ms
   number 5
   input_data:
     buffer_size: 1536 kb
   results:
     direction: 73.5001 ms
   number 6
   input_data:
     buffer_size: 3072 kb
   results:
     direction: 169.898 ms
   number 7
   input_data:
     buffer_size: 6144 kb
   results:
     direction: 450.124 ms


 investigation
  travel_order Reverse
 experiments
 -experiment:
   number 1
   input_data:
     buffer_size: 96 kb
   results:
     direction: 0.002535 ms
   number 2
   input_data:
     buffer_size: 192 kb
   results:
     direction: 0.002484 ms
   number 3
   input_data:
     buffer_size: 384 kb
   results:
     direction: 0.002455 ms
   number 4
   input_data:
     buffer_size: 768 kb
   results:
     direction: 0.003586 ms
   number 5
   input_data:
     buffer_size: 1536 kb
   results:
     direction: 0.003226 ms
   number 6
   input_data:
     buffer_size: 3072 kb
   results:
     direction: 0.002475 ms
   number 7
   input_data:
     buffer_size: 6144 kb
   results:
     direction: 0.002494 ms


 investigation
  travel_order Random
 experiments
 -experiment:
   number 1
   input_data:
     buffer_size: 96 kb
   results:
     direction: 24.9872 ms
   number 2
   input_data:
     buffer_size: 192 kb
   results:
     direction: 61.4112 ms
   number 3
   input_data:
     buffer_size: 384 kb
   results:
     direction: 141.612 ms
   number 4
   input_data:
     buffer_size: 768 kb
   results:
     direction: 318.609 ms
   number 5
   input_data:
     buffer_size: 1536 kb
   results:
     direction: 1052.44 ms
   number 6
   input_data:
     buffer_size: 3072 kb
   results:
     direction: 1197.95 ms
   number 7
   input_data:
     buffer_size: 6144 kb
   results:
     direction: 3293.02 ms
```
 Общий график с результатами всех исследований:
 
