type config;

type scope;
[@bs.val] external scope: scope = "scope";

[@bs.obj]
external makeConfig:
  (
    ~attachStacktrace: bool=?,
    ~blacklistUrls: array(string)=?,
    ~debug: bool=?,
    ~dist: string=?,
    ~enabled: bool=?,
    ~environment: string=?,
    ~ignoreErrors: array(string)=?,
    ~logLevel: int=?,
    ~maxBreadcrumbs: int=?,
    ~maxValueLength: int=?,
    ~release: string=?,
    ~sampleRate: int=?,
    ~whitelistUrls: array(string)=?,
    ~dsn: string=?,
    unit
  ) =>
  config =
  "";

[@bs.module "@sentry/browser"] external init: config => unit = "init";

[@bs.module "@sentry/browser"]
external configureScope: (scope => unit) => unit = "configureScope";

[@bs.send] external setExtras: (scope, Js.t('a)) => unit = "setExtras";

[@bs.send] external setExtra: (scope, string, 'a) => unit = "setExtra";

[@bs.send] external setTags: (scope, Js.t('a)) => unit = "setTags";

[@bs.send] external setTag: (scope, string, string) => unit = "setTag";

[@bs.send] external setUser: (scope, Js.t('a)) => unit = "setUser";

[@bs.module "@sentry/browser"]
external addBreadcrumbs: Js.t('a) => unit = "addBreadcrumbs";

[@bs.module "@sentry/browser"]
external captureMessage: string => unit = "captureMessage";

[@bs.module "@sentry/browser"]
external captureEvent: Js.t('a) => unit = "captureEvent";
