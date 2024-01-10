using UnityEngine;

namespace Builder
{
    public class Person
    {
        /* 필드 */
        string m_Name;
        int m_Age;

        public class Builder
        {
            /* 필드 */
            string m_Name;
            int m_Age;

            /* 프로퍼티 */
            public string Name => m_Name;
            public int Age => m_Age;

            /* Setter */
            public Builder SetName(string name)
            {
                m_Name = name;
                return this;
            }

            public Builder SetAge(int age)
            {
                m_Age = age;
                return this;
            }

            public Person Build() => new Person(this);
        }

        Person(Builder builder)
        {
            m_Name = builder.Name;
            m_Age = builder.Age;
        }

        /* API */
        public void Print()
        {
            Debug.Log(m_Name);
            Debug.Log(m_Age);
        }
    }
    public class Builder : MonoBehaviour
    {
        void Start()
        {
            var person = new Person.Builder()
                .SetName("홍길동")
                .SetAge(10)
                .Build();

            person.Print();
        }
    }
}
