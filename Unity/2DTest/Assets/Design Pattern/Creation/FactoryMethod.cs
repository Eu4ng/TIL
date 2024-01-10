using UnityEngine;

namespace FactoryMethod
{
    /* Animal */
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

    /* Factory */
    public abstract class AnimalFactory
    {
        public abstract Animal CreateAnimal();
    }

    public class DogFactory : AnimalFactory
    {
        public override Animal CreateAnimal()
        {
            Debug.Log("Bark");
            return new Dog();
        }
    }

    public class CatFactory : AnimalFactory
    {
        int m_Count = 0;

        public override Animal CreateAnimal()
        {
            m_Count++;
            Debug.Log("Cat Count : " + m_Count);

            return new Cat();
        }
    }

    public class FactoryMethod : MonoBehaviour
    {
        void Start()
        {
            AnimalFactory[] factories = new AnimalFactory[]
            {
                new CatFactory(),
                new DogFactory()
            };

            foreach (var factory in factories)
            {
                var animal = factory.CreateAnimal();
                animal.Speak();
            }
        }
    }
}
