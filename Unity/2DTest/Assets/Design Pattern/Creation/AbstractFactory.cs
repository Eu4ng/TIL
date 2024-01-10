using System;
using UnityEngine;

namespace AbstractFactory
{
    /* 몬스터 */
    public enum MonsterType
    {
        Normal,
        Epic,
        Boss
    }

    public abstract class Monster
    {
        public abstract void Attack();
    }

    public class Slime : Monster
    {
        public override void Attack()
        {
            Debug.Log("슬라임 공격 : 몸통 박치기");
        }
    }

    public class Bee : Monster
    {
        public override void Attack()
        {
            Debug.Log("벌 공격 : 독침");
        }
    }

    public class Golem : Monster
    {
        public override void Attack()
        {
            Debug.Log("골렘 공격 : 팔 휘두르기");
        }
    }

    public class Goblin : Monster
    {
        public override void Attack()
        {
            Debug.Log("고블린 공격 : 돌 던지기");
        }
    }

    public class Kraken : Monster
    {
        public override void Attack()
        {
            Debug.Log("크라켄 공격 : 집어 삼키기");
        }
    }

    public class Dragon : Monster
    {
        public override void Attack()
        {
            Debug.Log("드래곤 공격 : 화염 브레스");
        }
    }

    /* 팩토리 */
    public abstract class MonsterFactory
    {
        public abstract Monster Create(MonsterType monsterType);
    }

    public class FieldMonsterFactory : MonsterFactory
    {
        public override Monster Create(MonsterType monsterType)
        {
            return monsterType switch
            {
                MonsterType.Normal => new Slime(),
                MonsterType.Epic => new Goblin(),
                MonsterType.Boss => new Dragon(),
                _ => null
            };
        }
    }

    public class LakeMonsterFactory : MonsterFactory
    {
        public override Monster Create(MonsterType monsterType)
        {
            return monsterType switch
            {
                MonsterType.Normal => new Bee(),
                MonsterType.Epic => new Golem(),
                MonsterType.Boss => new Kraken(),
                _ => null
            };
        }
    }

    /* 클라이언트 */
    public class AbstractFactory : MonoBehaviour
    {
        void Start()
        {
            SpawnMonsters(new FieldMonsterFactory());
            SpawnMonsters(new LakeMonsterFactory());
        }

        void SpawnMonsters(MonsterFactory monsterFactory)
        {
            var monsterTypes = Enum.GetValues(typeof(MonsterType));
            foreach (var monsterType in monsterTypes)
            {
                var monster = monsterFactory.Create((MonsterType)monsterType);
                monster.Attack();
            }
        }
    }
}
