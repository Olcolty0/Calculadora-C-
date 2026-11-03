//biblioteca para incluir funções e objetos
#ifndef CLASSES_INCLUDED
#define CLASSES_INCLUDED

#define limpar "\033[0m"
#define preto "\033[30m"
#define vermelho "\033[31m"
#define verde "\033[32m"
#define amarelo "\033[33m"
#define azul "\033[34m"
#define magenta "\033[35m"
#define ciano "\033[36m"
#define branco "\033[37m"

struct basics
{
    class Soma
    {
        public:
            Soma(float a, float b) : numeroA(a), numeroB(b) {}

            float somar() const
            {
                return (numeroA + numeroB);
            }

        private:
            float numeroA;
            float numeroB;
    };

    class Subtracao
    {
        public:
            Subtracao(float a, float b) : sub(a), tra(b) {}

            float subtrair() const
            {
                return (sub - tra);
            }

        private:
            float sub;
            float tra;
    };

    class Multiplicacao
    {
        public:
            Multiplicacao(float a, float b) : multiplicando(a), multiplicador(b) {}

            float multiplicar() const
            {
                return (multiplicando * multiplicador);
            }

        private:
            float multiplicando;
            float multiplicador;
    };

    class Divisao
    {
        public:
            Divisao(float a, float b) : dividendo(a), divisor(b) {}

            float quociente() const
            {
                return (dividendo / divisor);
            }

        private:
            float dividendo;
            float divisor;
    };
};

struct extraz
{
    class Potencia
    {
        public:
            Potencia(float a) : expo(a) {}

            float ente() const
            {
                return (expo * expo);
            }

        private:
            float expo;
    };

    static float root_sqr(float a)
    {
        float X;

        X = a;
        X /= 2;

        for (int n = 0; n < 15; n++)
        {
            X = (X + (a / X)) / 2;
            X *= 1;
            a *= 1;
        }
        return X;
    }

    class Porcentagem
    {
        public:
            Porcentagem(float p, float b) : percentual(p), base(b) {} // construtor da classe

            float calcular() const
            {
                return (percentual / 100) * base;
            }

        private:
            float percentual;   // dados guardados dentro do objeto
            float base;
    };

    class Elevar
    {                                                            // A classe DEVE
        public:                                                 //  OBRIGATORIAMENTE
            Elevar(float a, float b) : base(a), expoent(b) {}  //   ter o nome do construtor

            float elevate()
            {
                float c = 1;
                if (expoent > 0)
                {
                    for (int k = 0; k < expoent; k++)
                    {
                        c *= base;
                    }
                }
                else if (expoent < 0)
                {
                    expoent *= -1;
                    for (int p = 0; p < expoent; p++)
                    {
                        c *= base;
                    }
                    c = 1 / c;
                }
                else
                {
                    c = 1;
                }
                return c;
            }
        private:
            float base;
            float expoent;
    };

};

#endif
