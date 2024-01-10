using UnityEngine;

namespace SimpleFactory
{
    public enum AnimalType
    {
        Cat,
        Dog
    }

    public abstract class Animal
    {
        public abstract void Speak();
    }

    public class Cat : Animal
    {
        public override void Speak()
        {
            Debug.Log("Cat");
        }
    }

    public class Dog : Animal
    {
        public override void Speak()
        {
            Debug.Log("Dog");
        }
    }

    public class AnimalFactory
    {
        public Animal CreateAnimal(AnimalType animalType)
        {
            Animal animal = animalType switch
            {
                AnimalType.Cat => new Cat(),
                AnimalType.Dog => new Dog(),
                _ => null
            };

            return animal;
        }
    }

    public class SimpleFactory : MonoBehaviour
    {
        readonly AnimalFactory m_AnimalFactory = new AnimalFactory();

        void Start()
        {
            var cat = m_AnimalFactory.CreateAnimal(AnimalType.Cat);
            var dog = m_AnimalFactory.CreateAnimal(AnimalType.Dog);

            cat.Speak();
            dog.Speak();
        }
    }
}
