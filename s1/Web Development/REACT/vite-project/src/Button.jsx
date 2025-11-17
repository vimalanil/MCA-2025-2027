import React from "react";
import clsx from "clsx";
import "./Button.css";

function Button({
  children,
  variant = "primary",
  size = "md",
  className,
  isLoading = false,
  leftIcon,
  rightIcon,
  disabled,
  ...props
}) {
  return (
    <button
      className={clsx(
        "btn",
        `btn-${variant}`,
        `btn-${size}`,
        className
      )}
      disabled={isLoading || disabled}
      {...props}
    >
      {/* Loading Spinner */}
      {isLoading && <span className="spinner"></span>}

      {/* Left Icon */}
      {!isLoading && leftIcon && (
        <span className="btn-icon">{leftIcon}</span>
      )}

      <span>{children}</span>

      {/* Right Icon */}
      {!isLoading && rightIcon && (
        <span className="btn-icon">{rightIcon}</span>
      )}
    </button>
  );
}

export default Button;
