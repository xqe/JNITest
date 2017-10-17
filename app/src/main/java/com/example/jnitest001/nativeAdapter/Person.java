package com.inpor.jnitest001.nativeAdapter;

/**
 * Created by xieqe on 2017/10/16.
 */

public class Person {
    public String name;
    public int num;
    public long id;
    public boolean isMale;
    public Skill skill;

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getNum() {
        return num;
    }

    public void setNum(int num) {
        this.num = num;
    }

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public boolean isMale() {
        return isMale;
    }

    public void setMale(boolean male) {
        isMale = male;
    }

    public Skill getSkill() {
        return skill;
    }

    public void setSkill(Skill skill) {
        this.skill = skill;
    }

    @Override
    public String toString() {
        return "Person{" +
                "name='" + name + '\'' +
                ", num=" + num +
                ", id=" + id +
                ", isMale=" + isMale +
                ", skill=" + skill.getSkill() +
                '}';
    }
}
