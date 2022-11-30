import React, { useState } from "react";
import { Layout, Form, Input, notification, Button, Row } from 'antd';
import { HeatMapOutlined } from '@ant-design/icons';
import { UserProperty, UserPattern } from "../@types/User";

function Login(): any
{
    const [loading, setLoading] = useState(false);
    const [form] = Form.useForm();
    const [user, setUser]: any = useState<UserProperty>(UserPattern);

    const handleOk = async () => {}

    return (
        <>
            <Layout className='login-container'>
                <Form
                    name="basic"
                    labelCol={{ span: 8 }}
                    wrapperCol={{ span: 16 }}
                    initialValues={{ remember: true }}
                    onFinish={handleOk}
                    form={form}
                    autoComplete="off"
                >
                    <Row align='middle' justify='center' className='logo'>
                        <HeatMapOutlined />
                    </Row>
                    <Form.Item
                        name="email"
                        rules={[{ required: true, message: 'Required email!' }]}
                    >
                        <Input
                            placeholder="Email"
                            type="text"
                            onChange={(val: any) => setUser({ ...user, email: val.target.value })}
                        />
                    </Form.Item>
                    <Form.Item
                        name="password"
                        rules={[{ required: true, message: 'Required password!' }]}
                    >
                        <Input
                            placeholder="Password"
                            type="password"
                            onChange={(val: any) => setUser({ ...user, password: val.target.value })}
                        />
                    </Form.Item>

                    <Button className='dark'>
                        Sign In
                    </Button>
                </Form>
            </Layout>
        </>
    );
};

export default Login;