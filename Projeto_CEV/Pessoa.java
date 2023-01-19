public abstract class Pessoa {
    protected String nome, sexo;
    protected int idade;
    protected float exp;

    public Pessoa(String nome, String sexo, int idade) {
        this.nome = nome;
        this.sexo = sexo;
        this.idade = idade;
        this.exp = 0.0f;
    }

    @Override
    public String toString() {
        return
            " nome='" + getNome() + "'" +
            ", sexo='" + getSexo() + "'" +
            ", idade='" + getIdade() + "'" +
            ", exp='" + getExp() + "'";
    }

    protected void ganharExp() {
        setExp(getExp() + 1.0f);
    }

    public String getNome() {
        return this.nome;
    }
    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getSexo() {
        return this.sexo;
    }
    public void setSexo(String sexo) {
        this.sexo = sexo;
    }

    public int getIdade() {
        return this.idade;
    }
    public void setIdade(int idade) {
        this.idade = idade;
    }

    public float getExp() {
        return this.exp;
    }
    public void setExp(float exp) {
        this.exp = exp;
    }
    
}
