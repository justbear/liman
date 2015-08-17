# Игровой движок Just Bear (RU)
* Больше информации о компании на [сайте Just Bear](http://justbear.org/);
* Условия участия в разработке на [странице работ](http://justbear.org/jobs/);
* Полная информация [о проектах в разработке](http://justbear.org/games/);
* Список задач по проекту в [трелло](https://trello.com/b/g1HdHrUA).

## Достигнутые Особенности
* Прорисовка объектов
* Расширяемая система актеров
* Базовая логика

## Структура проекта
* ``Actors`` актеры (игровые объекты), основанные на расширямых компонентах;
  * ``Actor``
  * ``CRenderable``
  * ``CMovable``
* ``Subsystems`` файлы подстистем
  * ``Application`` взаимодейтвие с компьютером и настройками игры
  * ``BaseGameLogic`` работа с подсистемами игры
  * ``LevelManager`` менеджер по управлению и предоставлению доступа к объетам определенного типа и параметров
  * ``ActorFactory`` фабрика для создания и обработки актеров
* ``Life``
  * ``Initialize`` инициализация
  * ``Loop`` итерации на основном цикле
  * ``Deinitialize`` деинициализация
* ``Ipnut`` подсистема ввода
* ``Graphics`` графика

## Список задач
* Последнее
  * Загрузка компонентов актеров
* Масштабное
  * Разделить ядро на состоявляющие (актеры, столкновения и физика, события, файловая система, графика)
* Библиотеки
  * Собрать список используемых в проекте библиотек с указанием версий, сайтов и лицензий
  * Перевести библиотеку glfw на новую версию
  * Обновить все используемые библиотеки
* Переработка системы актеров
  * Поправить хранение (в актере и в левл менеджере)
  * Создать методы доступа (по группе)
  * Переработать загрузчик
  * Создать экземпляр для примера
  * Довавить обратный парсер актора и компонента
* Ввод
  * Заняться проверкой координат мыши
  * Добавить поддержку контроллеров (включая настройки)
* Довести графику до ума
  * Добавить рескейл текстур в соотвтствии с разрешением в настройках
  * Решить проблему с загрузкой картинок большого разрешения
  * Сделать поддержу сложных атктеров из нескольких спрайтов
  * Сделать наброски анимационного компонента
* Загрузка и хранение игровых настроек
  * Разделить на пользовательсике и разработчика
* Система событий
  * Продумать и обсудить
  * Сделать схемы
  * Перевести ввод на события

## Структура кода
###Пример 1
````
class ClassName
{
public:
	ClassName();

	~ClassName();

private:
	int m_param1;
	char* m_pChar1;

}
````
###Пример 2
````
if(!statement)
{
	doSmth();
}
else if()
{
	noReallyDoSmth();
}
````

## Используемые библиотеки
| Название                               | Назначение                            | Применяемые Модули       | Версия
|----------------------------------------|---------------------------------------|--------------------------|-------------
| [stb](https://github.com/nothings/stb) | Загрузка изображение (png, jpg, etc.) | stb image                | v2.02
| [glfw](http://www.glfw.org/)           |                                       |                          |
| glew                                   |                                       |                          |
| glm                                    |                                       |                          |

# Just Bear Game Engine (EN)

* More information about company on [Just Bear website](http://justbear.org/).
* Condition of participation on [jobs page ](http://justbear.org/jobs/).
* Comprehensive information about projects in development on [special page](http://justbear.org/games/).