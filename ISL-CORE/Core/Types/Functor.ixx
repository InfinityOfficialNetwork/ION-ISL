export module ION.Core.Types.Functor;

export import ION.Core.Object;

export namespace ION::Core::Types {
    template<typename T, typename... Args>
    class Functor : public Object {
    public:
        Functor(T(*Function)(Args...)) : Function(Function) {}

        virtual T operator()(Args... args) const {
            return Function(args...);
        }

    private:
        T(*Function)(Args...);
    };
}