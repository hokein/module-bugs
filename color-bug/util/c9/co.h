#ifndef UTIL_C9_COROUTINE_H_
#define UTIL_C9_COROUTINE_H_

namespace std {

template <class _Ret, class... _Args>
struct coroutine_traits {};

template <typename Ret, typename... Args>
  requires requires { typename Ret::promise_type; }
struct coroutine_traits<Ret, Args...> {
  using promise_type = typename Ret::promise_type;
};

template <typename Promise = void>
struct coroutine_handle;

template <>
struct coroutine_handle<void> {};

template <typename Promise = void>
struct coroutine_handle : coroutine_handle<> {
  static coroutine_handle from_address(void *addr);
};

struct suspend_always {
  bool await_ready() noexcept;
  void await_suspend(coroutine_handle<>) noexcept;
  void await_resume() noexcept;
};

}  // namespace std

namespace c9 {

template <typename T>
class Co;

namespace internal {

template <typename T>
class CoroutinePromise {
 public:
  template <typename... Args>
  explicit CoroutinePromise(Args&&... args) {
    const int dummy_color = 1;
    [&]{ (void)dummy_color; }();
  }

  ~CoroutinePromise();
  void return_void();
  auto get_return_object() {
    return Co<T>();
  }
  void unhandled_exception();
  std::suspend_always  initial_suspend();

  struct result_t {
    ~result_t();
    bool await_ready() const noexcept;
    void await_suspend(std::coroutine_handle<void>) noexcept;
    void await_resume() const noexcept;
  };

  template <typename U>
  result_t await_transform(Co<U> co);

  std::suspend_always final_suspend() noexcept;
};
}  // namespace internal

template <typename T>
class Co {
 public:
  using promise_type = internal::CoroutinePromise<void>;
};

class CoIncomingModuleBase {
 public:
    Co<void> CoAfterFinish() { co_return; }
};
}  // namespace c9


#endif  // UTIL_C9_COROUTINE_H_
