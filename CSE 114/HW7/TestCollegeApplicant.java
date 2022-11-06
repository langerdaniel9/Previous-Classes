/*
 * Daniel Langer
 * 114662901
 */

abstract class CollegeApplicant {
    private String name;
    private String collegeAppliedTo;

    protected CollegeApplicant(String initName, String initCollegeAppliedTo) {
        name = initName;
        collegeAppliedTo = initCollegeAppliedTo;
    }

    public String getCollegeAppliedTo() {
        return collegeAppliedTo;
    }
}

class UndergradCollegeApplicant extends CollegeApplicant {
    private int SATScore;
    private double GPA;

    public UndergradCollegeApplicant(String initName, String initCollegeAppliedTo, int initSATScore, double initGPA) {
        super(initName, initCollegeAppliedTo);
        SATScore = initSATScore;
        GPA = initGPA;
    }
}

class GraduateCollegeApplicant extends CollegeApplicant {
    private String collegeOfOrigin;

    public GraduateCollegeApplicant(String initName, String initCollegeAppliedTo, String initCollegeOfOrigin) {
        super(initName, initCollegeAppliedTo);
        collegeOfOrigin = initCollegeOfOrigin;
    }

    public String transfer() {
        if (collegeOfOrigin.equals(this.getCollegeAppliedTo())) {
            return "from inside";
        } else {
            return "from outside";
        }
    }
}

public class TestCollegeApplicant {
    public static void main(String[] args) {
        UndergradCollegeApplicant person1 = new UndergradCollegeApplicant("Dave Smith", "SBU", 1340, 3.8);
        GraduateCollegeApplicant person2 = new GraduateCollegeApplicant("Jane Doe", "SBU", "SBU");
        GraduateCollegeApplicant person3 = new GraduateCollegeApplicant("John Deere", "Binghampton", "SBU");
        System.out.println("Person 2 is " + person2.transfer());
        System.out.println("Person 3 is " + person3.transfer());
    }
}
