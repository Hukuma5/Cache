# Cache
### Задача

Используя описанный выше способ обхода провести исследование зависимости времени чтения одного элемента массива от размера массива.

Обход совершить тремя способами:
- **прямой** (0, 16, 32, 48, ...);
- **обратный** (..., 64, 48, 32, 16, 0);
- **случайный** (например 32, 128, 0, 16, 48, 64 и т.д.).

Каждое исследование включает в себя серию эксперементов c определенными размерами.

Количество экспериментов в серии определяется следующим образом:

```cpp
1/2 * cache_sizes['1'] < 2^x < 2^(x+1) < ... < 2^(x+n) < 3/2 * cache_sizes['max']
```

### Пример

В примере ниже показано, что для процессора с тремя уровнями кэша (`2mb`, `4mb`, `8mb`)
необходимо провести серию из 5 эксперементов.

```cpp
cache_size['1'] = 2 mb;
cache_size['2'] = 4 mb;
cache_size['3'] = 8 mb;

// 1mb < 2mb < 4mb < 8mb < 12mb
```

### Отчет: 
Для большей точности эксперемента время замеряется для 10000000 обходов.

```yaml
investigaion:
  travel_variant: "direction"                
  experiments:                                      
  - experiment:                                     
      number: 1                                 
      input_data:                                
        buffer_size: "128 KB"             
      results:                                     
        duration: "348 ms"               
  - experiment:                                     
      number: 2                                 
      input_data:                                
        buffer_size: "256 KB"             
      results:                                     
        duration: "319 ms"
  - experiment:                                     
      number: 3                                 
      input_data:                                
        buffer_size: "512 KB"             
      results:                                     
        duration: "411 ms"
  - experiment:                                     
      number: 4                                 
      input_data:                                
        buffer_size: "1 mb"             
      results:                                     
        duration: "348 ms" 
  - experiment:                                     
      number: 5                                
      input_data:                                
        buffer_size: "2 mb"             
      results:                                     
        duration: "438 ms"
  - experiment:                                     
      number: 6                                 
      input_data:                                
        buffer_size: "4 mb"             
      results:                                     
        duration: "724 ms"
  - experiment:                                     
      number: 7                                 
      input_data:                                
        buffer_size: "8 mb"             
      results:                                     
        duration: "736 ms" 
  - experiment:                                     
      number: 8                                 
      input_data:                                
        buffer_size: "9 mb"             
      results:                                     
        duration: "643 ms"         
investigaion:
  travel_variant: "Back"                
  experiments:                                      
  - experiment:                                     
      number: 1                                 
      input_data:                                
        buffer_size: "128 KB"             
      results:                                     
        duration: "346 ms"               
  - experiment:                                     
      number: 2                                 
      input_data:                                
        buffer_size: "256 KB"             
      results:                                     
        duration: "345 ms"
  - experiment:                                     
      number: 3                                 
      input_data:                                
        buffer_size: "512 KB"             
      results:                                     
        duration: "358 ms"
  - experiment:                                     
      number: 4                                 
      input_data:                                
        buffer_size: "1 mb"             
      results:                                     
        duration: "365 ms" 
  - experiment:                                     
      number: 5                                
      input_data:                                
        buffer_size: "2 mb"             
      results:                                     
        duration: "390 ms"
  - experiment:                                     
      number: 6                                 
      input_data:                                
        buffer_size: "4 mb"             
      results:                                     
        duration: "550 ms"
  - experiment:                                     
      number: 7                                 
      input_data:                                
        buffer_size: "8 mb"             
      results:                                     
        duration: "756 ms" 
  - experiment:                                     
      number: 8                                 
      input_data:                                
        buffer_size: "9 mb"             
      results:                                     
        duration: "831 ms"       
investigaion:
  travel_variant: "Random"                
  experiments:                                      
  - experiment:                                     
      number: 1                                 
      input_data:                                
        buffer_size: "128 KB"             
      results:                                     
        duration: "536 ms"               
  - experiment:                                     
      number: 2                                 
      input_data:                                
        buffer_size: "256 KB"             
      results:                                     
        duration: "516 ms"
  - experiment:                                     
      number: 3                                 
      input_data:                                
        buffer_size: "512 KB"             
      results:                                     
        duration: "1339 ms"
  - experiment:                                     
      number: 4                                 
      input_data:                                
        buffer_size: "1 mb"             
      results:                                     
        duration: "1483 ms" 
  - experiment:                                     
      number: 5                                
      input_data:                                
        buffer_size: "2 mb"             
      results:                                     
        duration: "1683 ms"
  - experiment:                                     
      number: 6                                 
      input_data:                                
        buffer_size: "4 mb"             
      results:                                     
        duration: "780 ms"
  - experiment:                                     
      number: 7                                 
      input_data:                                
        buffer_size: "8 mb"             
      results:                                     
        duration: "9979 ms" 
  - experiment:                                     
      number: 8                                 
      input_data:                                
        buffer_size: "9 mb"             
      results:                                     
        duration: "11598 ms"           
```
![](https://github.com/bmstu-iu8-32-cpp-2020/lab-02-cache-Hukuma5/blob/master/график%20к%20LAB_02.png?raw=true)
