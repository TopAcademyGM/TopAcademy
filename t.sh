#!/bin/bash

# Установите разделитель, используемый в именах файлов
separator="_"

# Перебираем каждый файл в текущей директории, имеющий указанную структуру имени
for file in $(ls | grep '_'); do

  # Получаем старый префикс и старое окончание
  old_prefix=$(echo $file | cut -d$separator -f1)
  old_suffix=$(echo $file | cut -d$separator -f2)

  # Получаем новый префикс и новое окончание
  new_prefix=$old_suffix
  new_suffix=$old_prefix

  # Переименовываем файл, используя новое имя
#   mv $file $new_suffix${separator}*${separator}$new_prefix.extension
    echo 1.
    mv $file $new_prefix${separator}$new_suffix

done
